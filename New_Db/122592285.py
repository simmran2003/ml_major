from math import *
#from bisect import *
#from collections import *
#from random import *
#from decimal import *"""
#from heapq import *
#from random import *
import sys
input=sys.stdin.readline
#sys.setrecursionlimit(3*(10**5))
global flag
def inp():
    return int(input())
def st():
    return input().rstrip('\n')
def lis():
    return list(map(int,input().split()))
def ma():
    return map(int,input().split())
t=1
while(t):
    t-=1
    n,m,s,f=ma()
    r=[]
    for i in range(m):
        a=lis()
        r.append(a)
    res=''
    time=1
    i=0
    while(s!=f):
        #print(time,i)
        if((i<m and r[i][0]>time) or i>=m):
            if(s<f):
                res+='R'
                s+=1
            elif(s>f):
                res+='L'
                s-=1
            else:
                break
            time+=1
        elif(time==r[i][0]):
            if((s>=r[i][1] and s<=r[i][2])):
                time+=1
                i+=1
                res+='X'
                continue
            if(s>f):
                if(((s-1)>=r[i][1] and (s-1)<=r[i][2])):
                    time+=1
                    res+='X'
                    i+=1
                else:
                    res+='L'
                    s-=1
                    i+=1
                    time+=1
                continue
            if(s<f):
                if(((s+1)>=r[i][1] and (s+1)<=r[i][2])):
                    time+=1
                    res+='X'
                    i+=1
                else:
                    res+='R'
                    s+=1
                    i+=1
                    time+=1
                continue
            if(s==f):
                break
    print(res)
                
                
        
        
            
