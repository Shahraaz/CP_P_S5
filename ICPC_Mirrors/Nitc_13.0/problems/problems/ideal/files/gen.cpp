#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_C = 1e8;

void error(string s) {
  cerr << s << endl;
  exit(1);
};

ll arg(const map<string, string> &mp, const string &key, bool must_present = true) {
  if (!must_present && !mp.count(key)) return 0;
  assert(mp.count(key));
  return atoll(mp.find(key)->second.c_str());
}

vector<long long> gen_split(long long l, int n) {
  vector<long long> splits;
  do {
    splits.push_back(l);
    for (int i = 0; i < n; i++) {
      splits.push_back(rnd.next(1LL, l));
    }
    sort(splits.begin(), splits.end());
    splits.erase(unique(splits.begin(), splits.end()), splits.end());
    if ((int)splits.size() > n) {
      shuffle(splits.begin(), splits.end());
      splits.erase(splits.begin() + n, splits.end());
      sort(splits.begin(), splits.end());
    }
  } while ((int)splits.size() < n);
  for (int i = n - 1; i > 0; i--) {
    splits[i] -= splits[i - 1];
  }
  return splits;
}

struct pillar {
  int x, y, h;
};
struct Test {
  vector<pillar> a;

  void print() {
    cout << a.size() << endl;
    for (auto p : a) cout << p.x << " " << p.y << " " << p.h << endl;
  }
};

map<string, function<Test(map<string, string>)>> tests;

void init() {
  tests["Rand"] = [&](map<string, string> args) {
    int n = arg(args, "n");
    int c = arg(args, "c", 0);
    if (!c) c = MAX_C;
    int h = arg(args, "h", 0);
    if (!h) h = c;

    vector<pillar> a(n);
    for (auto &p : a) {
      p.x = rnd.next(-c, c);
      p.y = rnd.next(-c, c);
      p.h = rnd.next(1, h);
    }
    return Test({a});
  };
  tests["Max"] = [&](map<string, string> args) {
    int n = arg(args, "n");
    int c = arg(args, "c", 0);
    if (!c) c = MAX_C;

    vector<pillar> a;
    for (ll x : {-c, c}) {
      for (ll y : {-c, c}) {
        a.push_back({x, y, c});
      }
    }
    while ((int)a.size() < n) {
      pillar p;
      p.x = rnd.next(-c, c);
      p.y = rnd.next(-c, c);
      p.h = rnd.next(1, c);
      a.push_back(p);
    }
    return Test({a});
  };
  tests["Rect"] = [&](map<string, string> args) {
    int n = arg(args, "n");
    int h = arg(args, "h", 0);
    if (!h) h = MAX_C;
    int xl = arg(args, "xl");
    int xr = arg(args, "xr");
    int yl = arg(args, "yl");
    int yr = arg(args, "yr");

    vector<pillar> a(n);
    for (auto &p : a) {
      p.x = rnd.next(xl, xr);
      p.y = rnd.next(yl, yr);
      p.h = rnd.next(1, h);
    }
    return Test({a});
  };
  tests["Line"] = [&](map<string, string> args) {
    int n = arg(args, "n");
    int h = arg(args, "h", 0);
    if (!h) h = MAX_C;
    int x1 = arg(args, "x1");
    int y1 = arg(args, "y1");
    int x2 = arg(args, "x2");
    int y2 = arg(args, "y2");

    vector<pillar> a(n);
    for (auto &p : a) {
      double d = rnd.next();
      int x = (int)(x1 + (x2 - x1) * d);
      int y = (int)(y1 + (y2 - y1) * d);
      p.h = rnd.next(1, h);
    }
    return Test({a});
  };
}

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  init();

  map<string, string> args;
  string tp;
  for (int i = 1; i < argc; i++) {
    string cur = argv[i];
    int j = cur.find('=');
    if (j != -1) {
      string left = cur.substr(0, j);
      string right = cur.substr(j + 1);
      if (left == "type") tp = right;
      else args[left] = right;
    }
  }

  if (tests.count(tp)) {
    tests[tp](args).print();
  }
  else {
    error("<test_type>: \"" + tp + "\" was not expected");
  }

  return 0;
}
