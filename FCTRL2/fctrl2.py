#!/usr/bin/env python3
import math
def factorial(n):
    return math.factorial(n)


if __name__ == '__main__':
    testcases = int(input().strip())
    while (testcases > 0):
        n = int(input().strip())
        print (factorial(n))
        testcases -= 1

