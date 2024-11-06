from functools import cmp_to_key
n = int(input())
arr =[]
for i in range(n):
    arr.append(input())
def comp(a,b):
    return -1*(a + b <= b + a)
arr = sorted(arr, key = cmp_to_key(comp))
print("".join(arr))
