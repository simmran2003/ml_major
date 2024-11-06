import sys
import functools


def cmp(a, b):
    # print("compare ", a, b)
    if a + b < b + a:
        return -1
    elif a + b > b + a:
        return 1
    else:
        return 0


if __name__ == '__main__':
    print("".join(sorted([x.strip() for x in sys.stdin.readlines()[1:]],
                         key=functools.cmp_to_key(cmp))))
