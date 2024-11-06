# _
#####################################################################################################################

from itertools import accumulate


def main():
    input()
    pieces = tuple(value(strength, team) for strength, team in zip(map(int, input().split()), input()))
    return Bob_sMaxStrength(pieces)


def value(strength, team):
    if team == 'A':
        return strength

    return -strength


def Bob_sMaxStrength(pieces):
    return max(0, max(accumulate(pieces)), max(accumulate(pieces[::-1]))) - sum(piece for piece in pieces if piece < 0)


if __name__ == '__main__':
    print(main())
    # main()
