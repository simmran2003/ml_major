import sys
input = sys.stdin.readline

n, m = map(int, input().split())
a = [int(x) for x in input().split()]
arr=[0]*(m+1)
for x in a:
	if x <= m:
		arr[x] += 1
for i in range(m//2, 0, -1):
	for j in range(i*2, m+1, i):
		arr[j] += arr[i]
ind = arr.index(max(arr))
if ind == 0:
	print(1, 0)
	sys.exit(0)
print(ind, arr[ind])
for i, x in enumerate(a):
	if ind % x == 0:
		print(i + 1, end = " ")