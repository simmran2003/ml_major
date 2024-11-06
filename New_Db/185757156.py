def Xenia_and_Divisors():
    n = int(input())
    sequence = list(map(int, input().split()))

    num1C = sequence.count(1)
    num2C = sequence.count(2)
    num3C = sequence.count(3)
    num4C = sequence.count(4)
    num5C = sequence.count(5)
    num6C = sequence.count(6)
    num7C = sequence.count(7)

    if num5C != 0 or num7C != 0 or num1C != n//3 :
        print(-1)
    else:
        #Type 1 is 1 2 4, type 2 is 1 2 6 , type 3 is 1 3 6
        sequence_printed = []

        while num3C > 0 and num6C > 0:
            sequence_printed.append("1 3 6")
            num3C -= 1
            num6C -= 1

        while num2C > 0 and num4C > 0:
            sequence_printed.append("1 2 4")
            num2C -= 1
            num4C -= 1

        while num2C > 0  and num6C > 0:
            sequence_printed.append("1 2 6")
            num2C -= 1
            num6C -= 1
        if len(sequence_printed) == 0 or (num2C != 0 or num3C != 0 or num4C != 0 or num6C != 0):
            print(-1)
        else:
            for i in sequence_printed:
                print(i)



Xenia_and_Divisors()