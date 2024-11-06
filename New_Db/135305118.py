import os
import sys
from io import BytesIO, IOBase

# region fastio
BUFSIZE = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")

############# Importing modules and stuffs we require  ######################################################

try:
        import sys
        from functools import lru_cache, cmp_to_key
        from heapq import merge, heapify, heappop, heappush
        from math import *
        from collections import defaultdict as dd, deque, Counter as Cntr
        from itertools import combinations as comb, permutations as perm
        from bisect import bisect_left as bl, bisect_right as br, bisect, insort
        from time import perf_counter
        from fractions import Fraction
        import copy
        from copy import deepcopy
        import time
        from decimal import *
        starttime = time.time()
        mod = int(pow(10, 9) + 7)
        mod2 = 998244353 

        def data(): return sys.stdin.readline()
        def out(*var, end="\n"): sys.stdout.write(' '.join(map(str, var))+end)
        def L(): return list(sp())
        def sl(): return list(ssp())
        def sp(): return map(int, data().split())
        def ssp(): return map(str, data().split())
        def l1d(n, val=0): return [val for i in range(n)]
        def l2d(n, m, val=0): return [l1d(n, val) for j in range(m)]
        def A2(n,m): return [[0]*m for i in range(n)]
        def A(n):return [0]*n
        # sys.setrecursionlimit(int(pow(10,6)))
        # from sys import stdin
        # input = stdin.buffer.readline
        # I = lambda : list(map(int,input().split()))
        # import sys
        # input=sys.stdin.readline
        
        import random
        sys.stdin = open("input.txt", "r")
        sys.stdout = open("output.txt", "w")
except:
        pass
############# Importing modules and stuffs we require  ######################################################

n,k = L()
A = L()

x = Cntr(A)
F = [0 for i in range(k+1)]

for ele in sorted(x.keys()):
    for i in range(ele,k+1,ele):
        F[i]+=x[ele]
cnt = max(F)
lcm = F.index(cnt)
if cnt==0:
    print(1,0)
    print()
    exit()
print(lcm,cnt)
for i in range(n):
    if lcm%A[i]==0:
        print(i+1,end=" ")
print()
