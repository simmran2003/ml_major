#I = lambda: [int(i) for i in input().split()]
#import io, os, sys
#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline


# n = int(input())
# l1 = list(map(int,input().split()))
# n,x = map(int,input().split())
# s = input()
mod = 1000000007
# print("Case #"+str(_+1)+":",)

from collections import Counter,defaultdict,deque
#from heapq import heappush,heappop,heapify
import sys
import math
import bisect
from functools import cmp_to_key


for _ in range(1):
    n = int(input());l=[]
    for i in range(n):
        x = input()
        l.append(x)
    def compare(a,b):
        if a+b<b+a:
            return -1
        elif a+b>b+a:
            return 1
        else:
            return 0
        

    ans = sorted(l,key = cmp_to_key(compare))

    print(''.join(ans))
            
        
    
    
    
    
        
        
    
    
    
    
    
        
            
            
        
            
            
        
            
    























    
        
            
    
            
            


    
    
        






            
