#Mamma don't raises quitter.................................................
#manan is improving, keep hustling manan bhai ;)
from collections import deque as de
import math
import sys
from math import sqrt as sq
from math import floor as fl
from math import ceil as ce
from sys import stdin, stdout
import time
from  queue import PriorityQueue as pq
sys.setrecursionlimit(10**7)
from collections import Counter as cnt
from functools import  reduce

from itertools import groupby as gb
#from fractions import Fraction as fr
from bisect import bisect_left as bl, bisect_right as br
from typing import Coroutine

def factors(n):    
    return set(reduce(list.__add__, 
                ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0)))
    
class My_stack():
    def __init__(self):
        self.data = []
    def my_push(self, x):
        return (self.data.append(x))
    def my_pop(self):
        return (self.data.pop())
    def __iter__(self):
        return iter(self.data)
    def my_peak(self):
        return (self.data[-1])
    def my_contains(self, x):
        return (self.data.count(x))
    def my_show_all(self):
        return (self.data)
    def isEmpty(self):
      return len(self.data)==0
    def len(self):
        return len(self.data)
    

arrStack = My_stack() 

class graph():
    def __init__(self):
        self.graphdict = {}
    def add_edge(self, node, neighbor):
        if node not in self.graphdict:
            self.graphdict[node]=[neighbor]
        else:
            self.graphdict[node].append(neighbor)
    def show_edge(self):
        for node in self.graphdict:
            for neighbors in self.graphdict:
                print(node, neighbors)
    def show_graph(self):
        return self.graphdict

    


    
            

#decimal to binary   
def decimalToBinary(n): 
    return bin(n).replace("0b", "")
#binary to decimal
def binarytodecimal(n):
    return int(n,2)

def isPrime(n) : 
	if (n <= 1) : 
		return False
	if (n <= 3) : 
		return True
	if (n % 2 == 0 or n % 3 == 0) : 
		return False
	i = 5
	while(i * i <= n) : 
		if (n % i == 0 or n % (i + 2) == 0) : 
			return False
		i = i + 6
	return True

def get_prime_factors(number):
    prime_factors = []
    while number % 2 == 0:
        prime_factors.append(2)
        number = number / 2
    for i in range(3, int(math.sqrt(number)) + 1, 2):
        while number % i == 0:
            prime_factors.append(int(i))
            number = number / i

    if number > 2:
        prime_factors.append(int(number))
    return prime_factors

def get_frequency(list):
    dic={}
    for ele in list:
        if ele in dic:
            dic[ele] += 1
        else:
            dic[ele] = 1
    return dic

def Log2(x): 
    return (math.log10(x) / 
            math.log10(2)); 

 
# Function to get product of digits
def getProduct(n):
    product = 1
    while (n != 0):
        product = product * (n % 10)
        n = n // 10
    return product
#fucntion to find regular bracket sequence
def regularBracketsequence(str,arrStack):
    for i in range(len(str)):
        if str[i] =='(':
            arrStack.my_push(str[i])
        else:
            if arrStack.isEmpty():
                return False
            else:
                arrStack.my_pop()
    if arrStack.isEmpty():
        return True
    else:
        return False

#function to find LCM of two numbers
def lcm(x,y):
   lcm = (x*y)//math.gcd(x,y)
   return lcm

def isPowerOfTwo(n): 
    return (math.ceil(Log2(n)) == math.floor(Log2(n))); 
#to check whether the given sorted sequnce is forming an AP or not....
def checkisap(list):
    d=list[1]-list[0]
    for i in range(2,len(list)):
        temp=list[i]-list[i-1]
        if temp !=d:
            return False
    return True

#seive of erathanos
def primes_method5(n):
    out ={}
    sieve = [True] * (n+1)
    for p in range(2, n+1):
        if (sieve[p]):
            out[p]=1
            for i in range(p, n+1, p):
                sieve[i] = False
    return out
#fucntion to get unique number to a cell in a matrix
def id(i, j, col): #one based indexing and columnwise numeration
    ans= (i-1)*col
    ans+=j
    return ans

#function to get the sum of digits
def getSum(n): 
      
    strr = str(n)
    list_of_number = list(map(int, strr.strip()))
    return sum(list_of_number)
def checkperfectsquare(n):
    if (ce(sq(n)) == fl(sq(n))):
        return True
    else:
        return False
#this used for selecting r objects from n ojects
def combinatrics(n,r):
    num=n
    deno=n-r
    pr=1
    for i in range(num,deno,-1):
        pr*=i
    an=1
    for i in range(1,r+1):
        an*=i
    ans=pr//an
    return ans
#sorting ascending with 1 and descending wrt 2
def custumsort(l):
    return sorted(l, key=lambda x: (x[0], -x[1]))
    
#ceil  function gives wrong answer after 10^17 so i have to create my own :)
# because i don't want to doubt on my solution of 900-1000 problem set.
def ceildiv(x,y): 
    return (x+y-1)//y 
  
def di():return map(int, input().split())
def ii():return int(input())
def li():return list(map(int, input().split()))
def si():return list(map(str, input()))
def indict():
    dic = {}
    for index, value in enumerate(input().split()):
        dic[int(value)] = int(index)
    return dic
def frqdict(): 
    # by default it is for integer input. :)
    dic={}
    for index, value in enumerate(input().split()):
        if value not in dic:
            dic[value] =1
        else:
            dic[value] +=1
    return dic

#sys.stdin = open('input.txt', 'r')
#sys.stdout = open('output.txt', 'w')
#i am survivor! yes i am :)
n=ii()
p=li()
s=si()
if n==1:
    print(p[0])
else:
    ac=0
    bc=0
    for i in range(n):
        if s[i]=="A":
            ac+=p[i]
        else:
            bc+=p[i]
    if ac==0:
        print(bc)
    else:
        ans=bc
        lac=0
        lbc=0
        for i in range(n):
            if s[i]=="A":
                lac+=p[i]
            else:
                lbc+=p[i]
            rac=ac-lac
            rbc=bc-lbc
            tempwithlswap=rbc+lac
            tempwithrswap=lbc+rac
            ans=max(ans,tempwithlswap,tempwithrswap)
        print(ans)
            
            
        
    
    
    


            
            
            




    
    

    




        


        
            
            



        





        


1