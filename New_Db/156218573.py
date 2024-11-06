import os,sys
from io import BytesIO, IOBase

from collections import defaultdict,deque,Counter
from bisect import bisect_left,bisect_right
from heapq import heappush,heappop
from functools import lru_cache
from itertools import accumulate
import math

# Fast IO Region
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

# for _ in range(int(input())):
#     n = int(input())
#     a = list(map(int, input().split(' ')))
#     if sum(a) == 0:
#         print('NO')
#     elif sum(a) > 0:
#         print('YES')
#         print(*sorted(a, reverse=True))
#     else:
#         print('YES')
#         print(*sorted(a))

# for _ in range(int(input())):
#     n, k = list(map(int, input().split(' ')))
#     t, r = k // (n - 1), k % (n - 1)
#     ans = t * n + r
#     if r == 0: ans -= 1
#     print(ans)

# def solve():
#     s, t, a = list(map(int, input().split(' ')))
#     n = int(input())
#     if n == 0:
#         print(s)
#         return
#     nums = list(map(int, input().split(' ')))
#     while nums and nums[-1] > t - a:
#         nums.pop()
#     if not nums:
#         print(s)
#         return
#     b = [max(nums[0], s)]
#     for i in range(1, len(nums)):
#         b.append(max(nums[i], b[-1] + a))
#     if b[0] > s:
#         print(s)
#         return
#     for i in range(len(b) - 1):
#         if b[i + 1] - b[i] > a:
#             print(b[i] + a)
#             return
#     if b[-1] + a + a <= t:
#         print(b[-1] + a)
#         return
#     ans = nums[0] - 1
#     res = s - ans
#     for i in range(len(b)):
#         if b[i] - (nums[i] - 1) < res:
#             res = b[i] - (nums[i] - 1)
#             ans = nums[i] - 1
#     print(ans)
# solve()

n, m, s, f = list(map(int, input().split(' ')))
ans = []
a = []
for _ in range(m):
    t, l, r = list(map(int, input().split(' ')))
    a.append((t, l, r))
if s < f:
    t = 1
    i = 0
    while s < f:
        if i < m:
            ti, l, r = a[i]
        if i < m and t == ti:
            if l - 1 <= s <= r:
                ans.append('X')
            else:
                ans.append('R')
                s += 1
            t += 1
            i += 1
        else:
            ans.append('R')
            t += 1
            s += 1
else:
    t = 1
    i = 0
    while s > f:
        if i < m:
            ti, l, r = a[i]
        if i < m and t == ti:
            if l <= s <= r + 1:
                ans.append('X')
            else:
                ans.append('L')
                s -= 1
            t += 1
            i += 1
        else:
            ans.append('L')
            t += 1
            s -= 1
print(''.join(ans))

 	 					 						 				 						   	