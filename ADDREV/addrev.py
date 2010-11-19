#!/usr/bin/env python
import re

if __name__ == '__main__':
    while (1):
        testcases = int(raw_input().strip())
        while (testcases > 0):
            input = raw_input()
            list = map(int, re.findall(r'\d+', input))
            n1 = list[0]
            n2 = list[1]
            testcases -= 1
            print n1, n2
        break

