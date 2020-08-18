import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
n = int(line.strip())
assert 2 <= n <= 2 * 10**5

sum_m = 0
for i in range(n):
    line = sys.stdin.readline()
    print(repr(line))
    assert re.match('^[1-9][0-9]*( [1-9][0-9]*)+\n$', line)
    nums = list(map(int, line.strip().split()))
    assert len(nums) > 0
    m = nums[0]
    nums = nums[1:]
    assert len(nums) == m
    assert 1 <= m <= 2 * 10**5
    sum_m += m

    seen = set()
    for x in nums:
        assert 1 <= x <= 10**9
        assert x not in seen
        seen.add(x)

assert sum_m <= 2 * 10**5

assert sys.stdin.read() == ""
sys.exit(42)

