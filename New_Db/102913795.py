r, h = map(int, input().split())
res = h // r * 2
if 2 * (h % r) >= (3 ** .5) * r:
    res += 3
elif 2 * (h % r) >= r:
    res += 2
else:
    res += 1
print(res)