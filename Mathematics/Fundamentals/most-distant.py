#!/bin/python3

import os
import sys
import math

# Complete the solve function below.
def solve(coordinates):
    mxx = mxy = mxabsx = mxabsy = -1e10;
    mnx = mny = 1e10;
    for p in coordinates:
        if p[0] != 0:
            mxx = max(mxx,p[0]);
            mnx = min(mnx,p[0]);
            mxabsx = max(mxabsx,abs(p[0]));
        else:
            mxy = max(mxy,p[1]);
            mny = min(mny,p[1]);
            mxabsy = max(mxabsy,abs(p[1]));
        
    return max(max(mxx - mnx,mxy-mny), math.sqrt(mxabsx*mxabsx + mxabsy*mxabsy))

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    coordinates = []

    for _ in range(n):
        coordinates.append(list(map(int, input().rstrip().split())))

    result = solve(coordinates)

    fptr.write(str(result) + '\n')

    fptr.close()
