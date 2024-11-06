import sys
input = sys.stdin.readline


def x(a, b, c):
    q = []
    p = 1
    for j in range(m):
        t, l, r = map(int, input().split())
        if c == 0 and t != p:
            q.append('R' * (min(t - p, b - a)))
            a += (t-p)
        elif c == 1 and t != p:
            q.append('L' * (min(t - p, a - b)))
            a -= (t-p)
        if c == 0 and a < b:
            if l-2 < a <= r:
                q.append('X')
            else:
                q.append('R')
                a += 1
        elif c == 1 and a > b:
            if l <= a < r+2:
                q.append('X')
            else:
                q.append('L')
                a -= 1
        if (c == 0 and a >= b) or (c == 1 and a <= b):
            return ''.join(q)
        p = t+1
    if c == 0:
        q.append('R'*(b-a))
    else:
        q.append('L'*(a-b))
    return ''.join(q)


n, m, s, f = map(int, input().split())
if s < f:
    print(x(s, f, 0))
else:
    print(x(s, f, 1))