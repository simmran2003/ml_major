import sys
from functools import lru_cache, cmp_to_key
from heapq import merge, heapify, heappop, heappush
from math import ceil, floor, gcd, fabs, factorial, fmod, sqrt, inf, log
from collections import defaultdict as dd, deque, Counter as c
from itertools import combinations as comb, permutations as perm
from bisect import bisect_left as bl, bisect_right as br, bisect
# sys.setrecursionlimit(2*pow(10, 6))
# sys.stdin = open("input.txt", "r")
# sys.stdout = open("output.txt", "w")
mod = pow(10, 9) + 7
mod2 = 998244353
def data(): return sys.stdin.readline().strip()
def out(var): sys.stdout.write(str(var))
def outln(var): sys.stdout.write(str(var)+"\n")
def l(): return list(sp())
def sl(): return list(ssp())
def sp(): return map(int, data().split())
def ssp(): return map(str, data().split())
def l1d(n, val=0): return [val for i in range(n)]
def l2d(n, m, val=0): return [l1d(n, val) for j in range(m)]
 
 
n, m, s, f = sp()
answer = []
last = 0
for _ in range(m):
    ti, li, ri = sp()
    diff = ti-last-1
    if f < s:
        while f < s and diff:
            s -= 1
            diff -= 1
            answer.append('L')
    else:
        while f > s and diff:
            s += 1
            answer.append('R')
            diff -= 1
    if f < s:
        if li <= s <= ri or li <= s-1 <= ri:
            answer.append('X')
        else:
            answer.append('L')
            s -= 1
    elif f > s:
        if li <= s <= ri or li <= s+1 <= ri:
            answer.append('X')
        else:
            answer.append('R')
            s += 1
    else:
        break
    last = ti
if f > s:
    for i in range(f-s):
        answer.append('R')
elif f < s:
    for i in range(s-f):
        answer.append('L')
outln(''.join(answer))