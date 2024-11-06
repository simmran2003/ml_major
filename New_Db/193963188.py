input()
cnter = [0] * 8
for x in map(int, input().split()):
    cnter[x] += 1

used = []
for i1, i2, i3 in ((1, 2, 4), (1, 2, 6), (1, 3, 6)):
    v = min((cnter[i1], cnter[i2], cnter[i3]))
    cnter[i1] -= v
    cnter[i2] -= v
    cnter[i3] -= v
    for _ in range(v):
        used.append((i1, i2, i3))

if sum(cnter) == 0:
    for triple in used:
        print(' '.join(map(str, triple)))
else:
    print(-1)