#!/bin/python3

import os
import sys
import math

# Complete the solve function below.
def solve(a, b, x, y):
    return "YES" if math.gcd(a,b) == math.gcd(x,y) else "NO"
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        abxy = input().split()

        a = int(abxy[0])

        b = int(abxy[1])

        x = int(abxy[2])

        y = int(abxy[3])

        result = solve(a, b, x, y)

        fptr.write(result + '\n')

    fptr.close()
