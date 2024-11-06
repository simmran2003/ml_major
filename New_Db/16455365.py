from time import time
import sys

t = time()

def logger(s):
    print(s, time() - t, file = sys.stderr)
    global t
    t = time()

n, m = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
B, C = [0]*(m+1), [0]*(m+1)
logger('initialization: ')

for a in A:
    if a <= m: B[a] += 1
logger('B: ')

for i in range(2, m + 1):
    for j in range(i, m+1, i):
        C[j] += B[i]

logger('C: ')

k, l = 1, 0
for i in range(2, m+1):
    if C[i] > l:
        l = C[i]
        k = i
logger('finding lcm: ')

print(k, l + B[1])
for i, a in enumerate(A):
    if k%a == 0: sys.stdout.write(str(i+1) + ' ')
logger('print: ')
