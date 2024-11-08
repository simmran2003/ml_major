import sys
from functools import lru_cache, cmp_to_key
from heapq import merge, heapify, heappop, heappush
from math import *
from collections import defaultdict as dd, deque, Counter as C
from itertools import combinations as comb, permutations as perm
from bisect import bisect_left as bl, bisect_right as br, bisect, insort
from time import perf_counter
from fractions import Fraction
import copy
from copy import deepcopy
import time
starttime = time.time()
mod = int(pow(10, 9) + 7)
mod2 = 998244353

def data(): return sys.stdin.readline().strip()
def out(*var, end="\n"): sys.stdout.write(' '.join(map(str, var))+end)
def L(): return list(sp())
def sl(): return list(ssp())
def sp(): return map(int, data().split())
def ssp(): return map(str, data().split())
def l1d(n, val=0): return [val for i in range(n)]
def l2d(n, m, val=0): return [l1d(n, val) for j in range(m)]
try:
    # sys.setrecursionlimit(int(pow(10,6)))
    sys.stdin = open("input.txt", "r")
    # sys.stdout = open("output.txt", "w")
except:
    pass
def pmat(A):
    for ele in A: print(*ele,end="\n")

def func(s):
    s=str(int(s))
    return sum(int(ele) for ele in s)




n,m,s,f=L()
if s>f:
    step="L"
    d=-1
else:
    step="R"
    d=1
T={}
for i in range(m):
    t,x,y=L()
    T[t]=[x,y]
t=1

while(s!=f):
    if t in T:
        if T[t][0]<=s<=T[t][1] or T[t][0]<=s+d<=T[t][1]:
            print("X",end="")
            t+=1
            continue
    s+=d
    print(step,end="")
    t+=1

