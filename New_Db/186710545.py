from functools import cmp_to_key


def compare(a, b):
    if a + b == b + a:
        return 0
    return 1 if a + b > b + a else -1


if __name__ == '__main__':
    n = int(input().strip())
    print("".join(sorted([input().strip() for _ in range(n)], key=cmp_to_key(compare))))
