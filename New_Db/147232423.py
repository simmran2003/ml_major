import sys
import io, os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

import math
from functools import reduce
def lcm_base(x, y):
    return (x * y) // math.gcd(x, y)

def lcm_list(numbers):
    return reduce(lcm_base, numbers, 1)

N = 10**6+1

def main():

    spf = [-1]*(N+1)
    for i in range(N+1):
        spf[i] = i
    for i in range(2, int(math.sqrt(N))+1):
        if spf[i] == i:
            for j in range(i*2, N+1, i):
                if spf[j] == j:
                    spf[j] = i

    def factorize(n):
        d = {}
        while n != 1:
            p = spf[n]
            if p in d:
                d[p] += 1
            else:
                d[p] = 1
            n //= p
        return d

    def make_divisors(D):
        d = [1]
        for p, q in D.items():
            nd = []
            for x in range(0, q+1):
                y = pow(p, x)
                for k in d:
                    nd.append(k*y)
            d = nd
        return d

    n, m = map(int, input().split())
    A = list(map(int, input().split()))
    C = [0]*(m+1)
    for a in A:
        if a <= m:
            C[a] += 1

    kmax = 0
    l = 1
    for i in range(2, m+1):
        D = factorize(i)
        E = make_divisors(D)
        k = 0
        for e in E:
            k += C[e]
        if k > kmax:
            kmax = max(kmax, k)
            l = i
    ans = []
    B = []
    for i, a in enumerate(A):
        if l%a == 0:
            ans.append(i+1)
            B.append(a)
    l = lcm_list(B)
    kmax = len(ans)
    print(l, kmax)
    print(*ans)

if __name__ == '__main__':
    main()
