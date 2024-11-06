import sys
from array import array

input = lambda: sys.stdin.buffer.readline().decode().strip()
inp = lambda dtype: [dtype(x) for x in input().split()]
inp_2d = lambda dtype, n: [dtype(input()) for _ in range(n)]
inp_2ds = lambda dtype, n: [tuple(inp(dtype)) for _ in range(n)]
ceil1 = lambda a, b: (a + b - 1) // b

n, m, be, en = inp(int)
lst, ans = 1, array('u')
ch = 'R' if be < en else 'L'
inc = 1 if be < en else -1

for _ in range(m):
    t, l, r = inp(int)
    while be != en and lst < t:
        ans.append(ch)
        lst += 1
        be += inc

    lst = t + 1
    if be != en:
        if not (l <= be <= r or l <= be + inc <= r):
            be += inc
            ans.append(ch)
        else:
            ans.append('X')

print(''.join(ans + array('u', ch * abs(en - be))))
