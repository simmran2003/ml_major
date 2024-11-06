import sys

input = sys.stdin.readline

n, m, s, f = map(int, input().strip().split())
time = 1
for i in range(m):
    t, l, r = map(int, input().strip().split())
    while time < t and s!=f:
        time+=1
        if s < f:
            s += 1
            print('R', end='')
        else:
            s -= 1
            print('L', end='')
    if s==f:
        exit()
    time+=1
    if s < f:
        if (s < l and s + 1 < l) or (s > r and s + 1 > r):
            s += 1
            print('R', end='')
        else:
            print('X', end='')

    else:
        if (s < l and s - 1 < l) or (s > r and s - 1 > r):
            s -= 1
            print('L', end='')
        else:
            print('X', end='')

while s!=f:
    if s < f:
        s += 1
        print('R', end='')
    else:
        s -= 1
        print('L', end='')


