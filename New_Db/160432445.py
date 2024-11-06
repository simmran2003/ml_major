n, m = map(int, input().split())
a = [int(x) for x in input().split()]
s = {}
for x in a:
    s[x] = s.get(x, 0) + 1
b = [0] * (m + 1)
for x in s:
    k = x
    while k <= m:
        b[k] += s[x]
        k += x
l = b.index(max(b))
if l == 0:
    print('1 0')
    print()
else:
    ans = []
    for i in range(len(a)):
        if l % a[i] == 0:
            ans.append(str(i + 1))
    print(l, len(ans))
    print(' '.join(ans))
