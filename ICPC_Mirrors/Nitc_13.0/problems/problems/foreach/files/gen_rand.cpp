#include <numeric>
#include <functional>
#include "testlib.h"

std::vector<int> rand_vector(int n, int c) {
  std::vector<int> v(n);
  for (int i = 0; i < n; i++) {
    v[i] = rnd.next(239 * c) / 239; // testlib's random over 2 is not good
  }
  return v;
}

std::vector<int> zero_one_vector(int n, int) {
  std::vector<int> v(n);
  for (int i = 0; i < n; i++) {
    v[i] = i % 2;
  }
  return v;
}

std::vector<int> one_zero_vector(int n, int) {
  std::vector<int> v(n);
  for (int i = 0; i < n; i++) {
    v[i] = (i % 2) ^ 1;
  }
  return v;
}



int main(int argc, char **argv) {
  registerGen(argc, argv, 1);
  ensure(argc >= 5);
  int n = atoi(argv[1]);
  int c = atoi(argv[2]);

  std::map<std::string, std::function<std::vector<int>(int, int)>> firsts;

  firsts.emplace("rand", rand_vector);
  firsts.emplace("perm", [](int n, int c) {
    ensure(c >= n);
    std::vector<int> res(n);
    std::iota(res.begin(), res.end(), 1);
    return res;
  });
  firsts.emplace("01", zero_one_vector);
  firsts.emplace("10", one_zero_vector);

  std::map<std::string, std::function<std::vector<int>(int, int, const std::vector<int>&)>> seconds;
  seconds.emplace("rand", [](int n, int c, const std::vector<int>&) { return rand_vector(n, c);});
  seconds.emplace("same", [](int, int, const std::vector<int>& a) { return a; });
  seconds.emplace("shuffle", [](int, int, std::vector<int> a) {
    shuffle(a.begin(), a.end());
    return a;
  });
  seconds.emplace("yes", [](int n, int, std::vector<int> a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    shuffle(a.begin(), a.end());
    auto res = rand_vector(n, a.size());
    for (int &x : res) {
      x = a[x];
    }
    return res;
  });
  seconds.emplace("01", [](int n, int c, const std::vector<int>&) { return zero_one_vector(n, c);});
  seconds.emplace("10", [](int n, int c, const std::vector<int>&) { return one_zero_vector(n, c);});

  ensure(firsts.count(argv[3]));
  ensure(seconds.count(argv[4]));
  auto first = firsts[argv[3]](n, c);
  auto second = seconds[argv[4]](n, c, first);

  std::vector<int> colors(100);
  std::iota(colors.begin(), colors.end(), 1);
  shuffle(colors.begin(), colors.end());
  colors.resize(c);

  printf("%d\n", n);
  for (const auto& v : {first, second}) {
    for (int i = 0; i < n; i++) {
      printf("%d%c", colors[v[i]], " \n"[i == n - 1]);
    }
  }
}
