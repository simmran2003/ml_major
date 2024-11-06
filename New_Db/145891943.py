import math


def main_function():
    n, p = [int(i) for i in input().split(" ")]
    customers = [input() for i in range(n)]
    counter = 0
    customers.reverse()
    for i in range(len(customers)):
        if i == 0:

                starter = 1
                counter += int(0.5 * p)
        else:
            if len(customers[i]) == 8:
                counter += int((starter + 0.5) * p)
                starter += starter + 1
                starter = int(starter)

            else:
                counter += int((starter)) * p
                starter += starter
                starter = int(starter)
           # print(customers[i], starter, counter)


    print(counter)















if __name__ == '__main__':
    main_function()