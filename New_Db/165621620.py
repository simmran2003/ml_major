import itertools

def magic(lst):
    lst1,lst2=lst[0],lst[1]
    c=itertools.accumulate
    a=[-i if j=='B' else i for i,j in zip(lst1,lst2)]
    b=sum(lst1[i] if lst2[i] == 'B' else 0 for i in range(n))
    ans=b+max(0, max(c(a)), max(c(a[::-1])))
    return ans

n=int(input())
a=list(map(int,input().split()))
b=input()
print(magic([a,b]))
