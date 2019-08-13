#!/bin/python3

if __name__ == '__main__':
    timeCharged = float(input())
    if timeCharged >= 4.00:
        print(round(8.00,2))
    else:
        print(round(2*timeCharged,2))
