from collections import Counter


def main():
    n = get_int()
    nums = get_list_int()
    num_counter = Counter(nums)
    num_groups = n // 3

    if (
        num_counter[1] != num_groups
        or (num_counter[2] + num_counter[3] != num_groups)
        or (num_counter[4] + num_counter[6] != num_groups)
    ):
        print(-1)
        return

    groups = []

    for _ in range(num_groups):
        if num_counter[2]:
            num_counter[2] -= 1
            if num_counter[4]:
                num_counter[4] -= 1
                groups.append("1 2 4")
            elif num_counter[6]:
                num_counter[6] -= 1
                groups.append("1 2 6")
            else:
                print(-1)
                return
        else:
            if num_counter[3]:
                num_counter[3] -= 1
                if num_counter[6]:
                    num_counter[6] -= 1
                    groups.append("1 3 6")
                else:
                    print(-1)
                    return

    for g in groups:
        print(g)


def get_int() -> int:
    return int(input())


def get_list_int() -> list[int]:
    return [int(x) for x in input().split(" ")]


def get_list_str() -> list[str]:
    return input().split(" ")


if __name__ == "__main__":
    main()
