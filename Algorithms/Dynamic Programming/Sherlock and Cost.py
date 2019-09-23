#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the cost function below.
def cost(B):
    l,h = 0,0
    for i in range(1,len(B)):
        hl = abs(B[i-1]-1)
        lh = abs(B[i]-1)
        hh = abs(B[i]-B[i-1])

        lw = max(l,h+hl)
        h = max(l + lh,h+hh)
        l = lw

    return max(l,h)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        n = int(input())

        B = list(map(int, input().rstrip().split()))

        result = cost(B)

        fptr.write(str(result) + '\n')

    fptr.close()
