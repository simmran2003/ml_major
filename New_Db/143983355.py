from itertools import accumulate
n = int(input())
arr = [int(i) for i in input().split()]
s = input().rstrip()

sm = [i*(1 - 2*(x == "B")) for i, x in zip(arr, s)]

acc1 = [0] + list(accumulate(sm))
acc2 = [0] + list(accumulate(sm[::-1]))
t = max(max(acc1), max(acc2))

print(sum(i* (x=="B") for i, x in zip(arr, s)) + t)