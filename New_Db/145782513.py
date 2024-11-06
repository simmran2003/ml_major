#!/usr/bin/python
import sys
input = lambda: sys.stdin.readline().strip()
n, p = [int(x) for x in input().split()]
ops = [input() for _ in range(n)]
apples = 0
ans = 0
for op in reversed(ops):
    if op == 'half':
        apples *= 2
    else:
        apples = apples * 2 + 1
    ans += apples * p // 2
print(ans)
