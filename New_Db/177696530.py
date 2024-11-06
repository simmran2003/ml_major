# https://codeforces.com/problemset/problem/632/C
from functools import cmp_to_key

def compare(x, y):
    if x == y: return 0
    i,j = 0,0
    while i < len(x) and j < len(y):
        if x[i] != y[j]: break
        i += 1
        j += 1
    if i == len(x):
        return compare(x, y[j:])
    if j == len(y):
        return compare(x[i:],y)
    if x[i] > y[j]: return 1
    return -1
    #  return x[0] - y[0] # x greater than y this is positive
 
N = int(input())
strs =  sorted([input() for _ in range(N)], key=cmp_to_key(compare))
print(''.join(strs))




