import itertools

def magic(lst):
    lst1,lst2=lst[0],lst[1]
    g=itertools.accumulate
    v=[-x if y == 'B' else x for x,y in zip(lst1,lst2)]
    s=sum(lst1[i] if lst2[i] == 'B' else 0 for i in range(n))
    ans=(s+max(0, max(g(v)), max(g(v[::-1]))))
    return ans

n=int(input())
a=list(map(int,input().split()))
b=input()
print(magic([a,b]))
