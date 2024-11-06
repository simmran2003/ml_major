from collections import defaultdict, deque
from functools import lru_cache
from heapq import heappush, heappop
from bisect import bisect_right, bisect_left
from fractions import Fraction as frac
import math
hpop = heappop
hpush = heappush
MOD = 10**9 + 7

def calc(x):
    d_sum = sum(map(int,str(x)))
    return x*x + d_sum *x

def solution():
    n,m,s,f = map(int, input().split())
    watch = defaultdict(lambda:(-1,-1))
    for _ in range(m):
        t,l,r = map(int, input().split())
        watch[t] = (l,r)

    i = 1
    cur = s
    while True:
        if cur == f:
            return

        dir = 1 if f > s else -1
        l,r = watch[i]
        if l <= cur <= r or l <= cur + dir <= r:
            print("X", end="")
        else:
            print("R" if dir > 0 else "L", end="")
            cur += dir 
        i += 1


def main():
    t = 1
    #t = int(input())
    for _ in range(t):
        solution() 
 
import sys
import threading
sys.setrecursionlimit(1 << 30)
threading.stack_size(1 << 27)
thread = threading.Thread(target=main)
thread.start(); thread.join()
#main()
