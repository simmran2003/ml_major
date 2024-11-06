def main():
    from collections import Counter
    n, m = map(int, input().split())
    l = list(map(int, input().split()))
    m += 1
    tmp = Counter(x for x in l if 1 < x < m)
    num = [0] * m
    for x, v in tmp.items():
        for i in range(x, m, x):
            num[i] += v
    lcm = max(range(m), key=num.__getitem__)
    if lcm:
        tmp = {x for x in tmp.keys() if not lcm % x}
        tmp.add(1)
        res = [i for i, x in enumerate(l, 1) if x in tmp]
    else:
        res, lcm = [i for i, x in enumerate(l, 1) if x == 1], 1
    print(lcm, len(res))
    if res:
        print(' '.join(map(str, res)))


if __name__ == '__main__':
    main()
