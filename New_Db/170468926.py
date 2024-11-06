from collections import defaultdict,Counter
import math
import bisect
from itertools import accumulate
from math import ceil, log
from functools import lru_cache, cmp_to_key
from sys import stdin, stdout

def strg(idx,a,b,i,n1,n2):
    if i == 0:
        if idx < n1:
            return a[idx]
        else:
            return b[idx-n1]
    else:
        if idx < n2:
            return b[idx]
        else:
            return a[idx-n2]
        
        
        
def strcmp(a,b):
    n1 = len(a)
    n2 = len(b)

    for idx in range(n1+n2):
        t1 = strg(idx,a,b,0,n1,n2)
        t2 = strg(idx,a,b,1,n1,n2)
     #   print(t1,t2)
        if t1 > t2:
            return 1
        elif t1 < t2:
            return -1
    return -1    

def read():
    return stdin.readline().rstrip()
 
    
total = int(read())
x = []
for _ in range(total):
    x.append(read())
#    
    
  
    
x = sorted(x,key = cmp_to_key(strcmp))
print(''.join(x))    
    
    
    
    
    
    
    
    
    
    
    
#    i,j = ([int(p) for p in read().split()])
#    x.append((i,1))
#    x.append((j,-1))

#y = sorted(range(2*total),key = lambda y:x[y][0])
#
#s = 0
#m = 0
##print(y)
#for i in y:
#    s+= x[i][1]
#    if s >m:
#        m=s
#    
#print(m)