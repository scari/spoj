#!/usr/bin/env python
import math

def is_perfect(n):
    return isinstance(math.sqrt(n), int)

def get_all_pairs(n):
    xy = []
    for x in xrange(n, 1, -1):
        for y in xrange(x-1, 0, -1):
            xy.append((x, y))
    return xy

def get_all_perfect(x, y):
    if is_perfect(x*y):
        print x*y
        xy.append((x,y))
    return (x, y)

if __name__ == '__main__':
    while (1):
        testcases = int(raw_input().strip())
        while (testcases > 0):
            n = raw_input()
            print [get_all_perfect(x, y) for x, y in get_all_pairs(int(n))]

