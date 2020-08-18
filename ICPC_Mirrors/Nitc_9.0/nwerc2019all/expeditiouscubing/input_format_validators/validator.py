#!/usr/bin/env python3
import sys
import re

NUM = r'([1-9]\.[0-9]{2}|1[0-9]\.[0-9]{2}|20\.00)'

line = sys.stdin.readline()
assert re.match(f'^{NUM} {NUM} {NUM} {NUM}\n$', line)

line = sys.stdin.readline()
assert re.match(f'^{NUM}\n$', line)

assert not sys.stdin.read()
sys.exit(42)

