from functools import cmp_to_key
n=int(input())
arr=[]
for i in range(n):
    arr.append(input())

sorted_words=sorted(arr, key=cmp_to_key(lambda x, y: 2*(x+y>y+x)-1))
print(''.join(sorted_words))