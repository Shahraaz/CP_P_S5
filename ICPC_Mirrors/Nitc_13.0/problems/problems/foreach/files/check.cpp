#include "testlib.h"

constexpr int MAXK = 10000;
constexpr int MAXV = 100;
const std::string prefix = "foreach ($a as ";
const std::string middle = "$x) if ($x == ";
const std::string suffix = ") break;";

bool parseCommand(InStream &out, const std::string& command, bool &ref, int &value) {
  if (command.size() < prefix.size() + 1 + middle.size() + 1 + suffix.size()) {
    return false;
  }
  if (command.substr(0, prefix.size()) != prefix) {
    return false;
  }
  if (command.substr(prefix.size() + 1, middle.size()) != middle) {
    return false;
  }
  if (command.substr(command.size() - suffix.size()) != suffix) {
    return false;
  }
  ref = command[prefix.size()] == '&';
  std::string int_id = command.substr(prefix.size() + 1 + middle.size(),
                                      command.size() - suffix.size() - prefix.size() - 1 - middle.size());
  long long value_long = stringToLongLong(out, int_id.c_str());
  if (!(1 <= value_long && value_long <= MAXV)) {
    return false;
  }
  value = value_long;
  return true;
}

int check(std::vector<int> a, const std::vector<int> &b, InStream &out) {
  int ans = out.readInt(-1, MAXK, "k");
  out.readEoln();
  if (ans == -1)
    return ans;
  int local = 0;
  int *x = &local;
  for (int i = 0; i < ans; i++) {
    bool ref = false;
    int value = 0;
    std::string command = trim(out.readLine());
    if (!parseCommand(out, command, ref, value)) {
      out.quitf(_wa, "Can't parse line: \"%s\"", compress(command).c_str());
    }
    if (ref) {
      for (int i = 0; i < (int)a.size(); i++) {
        x = &a[i];
        if (*x == value) {
          break;
        }
      }
    } else {
      for (int i = 0; i < (int)a.size(); i++) {
        *x = a[i];
        if (*x == value) {
          break;
        }
      }
    }
  }
  if (a != b) {
    out.quitf(_wa, "Wrong array state after %d commands", ans);
  }
  return ans;
}

int main(int argc, char **argv) {
  registerTestlibCmd(argc, argv);
  int n = inf.readInt();
  auto a = inf.readInts(n);
  auto b = inf.readInts(n);

  int ja = check(a, b, ans);
  int pa = check(a, b, ouf);
  if (ja == -1 && pa == -1) {
    quitf(_ok, "No solution");
  }
  if (ja != -1 && pa != -1) {
    quitf(_ok, "%d commands", pa);
  }
  if (pa == -1) {
    quitf(_wa, "Solution not found, but exits");
  }
  quitf(_fail, "Jury didn't found solution, but participant did");
}
