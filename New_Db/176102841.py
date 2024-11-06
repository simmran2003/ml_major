from sys import stdin
input=lambda :stdin.readline()[:-1]

def compare(a,b):
  return a+b<=b+a


def merge(l, r):
    new = []
    ln = 0
    rn = 0
    while ln < len(l) and rn < len(r):
        if compare(l[ln],r[rn]):
            new.append(l[ln])
            ln += 1
        else:
            new.append(r[rn])
            rn += 1
    for i in range(ln, len(l)):
        new.append(l[i])
    for i in range(rn, len(r)):
        new.append(r[i])
    return new
 
def MergeSort(l):
    if len(l) == 0:
        return []
    if len(l) == 1:
        return l
    else:
        a = l[:len(l)//2]
        b = l[len(l)//2:]
        return merge(MergeSort(a), MergeSort(b))

n=int(input())
s=[input() for i in range(n)]
s=MergeSort(s)
print(''.join(s))