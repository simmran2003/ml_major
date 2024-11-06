from sys import stdin
input = stdin.buffer.readline
n, m = map(int, input().split())
cnt = [0] * (m + 1)
*b, = map(int, input().split())
for i in b:
	if i <= m:
		cnt[i] += 1
a = [0] * (m + 1)
for i in range(1, m + 1):
	for j in range(i, m + 1, i):
		a[j] += cnt[i]
mx = idx = 0
for i in range(1, m + 1):
	if mx < a[i]:
		mx, idx = a[i], i
if mx == 0:
	exit(print(1, 0))
print(idx, mx)
for i in range(n):
	if idx % b[i] == 0:
		print(i + 1)