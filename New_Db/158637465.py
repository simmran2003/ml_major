import sys
import itertools
 
f = sys.stdin
g = itertools.accumulate
 
n = int(f.readline())
p = list(map(int, f.readline().split()))
c = f.readline()
 
v = [-x if y == 'B' else x for x,y in zip(p,c)]
s = sum(p[i] if c[i] == 'B' else 0 for i in range(n))
print(s+max(0, max(g(v)), max(g(v[::-1]))))