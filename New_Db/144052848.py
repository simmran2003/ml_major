MOD, ROOT = 998244353, 3
I = lambda: [int(i) for i in input().split()]


##############################################
def ntt(a, inv=0):
    n = len(a)
    w = [1] * (n >> 1)
    w[1] = pow(ROOT, (MOD - 1) // n * (inv * (MOD - 3) + 1), MOD)

    for i in range(2, n >> 1):
        w[i] = (w[i - 1] * w[1]) % MOD

    rev = [0] * n
    for i in range(n):
        rev[i] = rev[i >> 1] >> 1
        if i & 1:
            rev[i] |= n >> 1
        if i < rev[i]:
            a[i], a[rev[i]] = a[rev[i]], a[i]

    log_n = (n + 1).bit_length()
    for i in range(1, log_n):
        half, diff = 1 << (i - 1), log_n - i - 1
        for j in range(0, n, 1 << i):
            for k in range(j, j + half):
                v = (w[(k - j) << diff] * a[k + half]) % MOD
                a[k + half] = a[k] - v
                a[k] += v

    if not inv: return
    inv_n = pow(n, MOD - 2, MOD)
    for i in range(n):
        a[i] = (a[i] * inv_n) % MOD


def ntt_conv(a, b):
    l1, l2 = len(a), len(b)
    s = l1 + l2 - 1
    n = 1 << s.bit_length()
    a += [0] * (n - l1)
    b += [0] * (n - l2)
    ntt(a)
    ntt(b)
    for i in range(n):
        a[i] = (a[i] * b[i]) % MOD
    ntt(a, True)
    del a[s:]
##############################################

n, k = I()
A = I()
N = max(A) + 1

pol = [0]*N
for x in A: pol[x] = 1
arr = [pol[:] for _ in range(k)]

def prod(l):
    n = len(l)
    if n == 1: return l[0]
    lft = prod(l[:n//2])
    rgh = prod(l[n//2:])
    ntt_conv(lft, rgh)
    return [int(i != 0) for i in lft]

pol = prod(arr)
ans = [i for i, x in enumerate(pol) if x == 1]
print(" ".join(str(x) for x in ans))