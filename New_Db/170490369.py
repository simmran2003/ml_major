r, h = [int(xx) for xx in input().split()]
if r <= h:
    if h / r - h // r <= r / 7:
        print(max(2 * int(((h + r / 7)) // r) + 1, int((h + r / 2) // r * 2)))
    else:
        print(max(2 * int(((h)) // r) + 2, int((h + r / 2) // r * 2)))
else:
    if h >= r * (3 ** 0.5) / 2:
        print(3)
    elif h >= r / 2:
        print(2)
    else:
        print(1)

