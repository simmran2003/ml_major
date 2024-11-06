import sys
input = lambda :sys.stdin.readline()[:-1]
ni = lambda :int(input())
na = lambda :list(map(int,input().split()))
yes = lambda :print("yes");Yes = lambda :print("Yes");YES = lambda : print("YES")
no = lambda :print("no");No = lambda :print("No");NO = lambda : print("NO")
#######################################################################
from functools import cmp_to_key
def cmp(x,y):
    if x+y==y+x:return 0
    if x+y<y+x:
        return -1
    else:
        return 1
n = ni()
s = [input() for i in range(n)]
s = sorted(s,key = cmp_to_key(cmp))
print("".join(s))
