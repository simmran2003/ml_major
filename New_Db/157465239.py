import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def ntt(f, l, x, r, mod):
    u, v = 1, l // 2
    x0 = x
    while v:
        y = [1]
        for _ in range(v):
            y.append(y[-1] * r[x0] % mod)
        for i in range(u):
            a = 2 * i * v
            b = a + v
            for j in range(v):
                fa, fb = f[a + j], f[b + j]
                f[a + j] = (fa + fb) % mod
                f[b + j] = (fa - fb) * y[j] % mod
        u *= 2
        v //= 2
        x0 -= 1
    return

def intt(f, l, ir, mod):
    u, v = 1, l // 2
    x0 = 1
    while v:
        y = [1]
        for _ in range(u):
            y.append(y[-1] * ir[x0] % mod)
        for i in range(v):
            a = 2 * i * u
            b = a + u
            for j in range(u):
                fa, fb = f[a + j], f[b + j]
                f[a + j] = (fa + fb * y[j]) % mod
                f[b + j] = (fa - fb * y[j]) % mod
        u *= 2
        v //= 2
        x0 += 1
    return

def fft(f, g, z):
    lf, lg = len(f), len(g)
    c = lf + lg - 1
    x = len(bin(c)) - 2
    m = pow(2, x)
    f += [0] * (m - lf)
    ntt(f, m, x, r, mod)
    if z:
        g += [0] * (m - lg)
        ntt(g, m, x, r, mod)
        fg = [i * j % mod for i, j in zip(f, g)]
    else:
        fg = [pow(i, 2, mod) for i in f]
    intt(fg, m, ir, mod)
    ans = [1 if fg[i] else 0 for i in range(c)]
    return ans

def f(f, g):
    ans = [0] * (len(f) + len(g))
    for i in range(len(f)):
        for j in range(len(g)):
            if f[i] * g[j]:
                ans[i + j] = 1
    return ans

n, k = map(int, input().split())
a = list(map(int, input().split()))
ok = [0] * (max(a) + 1)
for i in a:
    ok[i] = 1
now = []
p2 = 1
mod, y = 998244353, 3
r = [pow(y, (mod - 1) >> i, mod) for i in range(21)]
ir = [pow(i, mod - 2, mod) for i in r]
while k:
    if k & p2:
        if not now:
            now = list(ok)
        else:
            now = fft(list(ok), now, 1)
        k ^= p2
        while not now[-1]:
            now.pop()
    ok = fft(list(ok), ok, 0)
    while not ok[-1]:
        ok.pop()
    p2 *= 2
ans = []
for i in range(len(now)):
    if now[i]:
        ans.append(i)
sys.stdout.write(" ".join(map(str, ans)))