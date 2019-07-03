#!/usr/bin/python

# Head ends here

import sys # Library for INT_MAX 

def next_move(posr, posc, board):
    if(board[posr][posc] == 'd'):
        print("CLEAN")
        return
    mn = 100000
    nxt = [0,0]
    for i in range(0,5):
        for j in range(0,5):
            if board[i][j] == 'd':
                distance = abs(posr-i) + abs(posc-j)
                if distance < mn:
                    mn = distance
                    nxt[0] = i
                    nxt[1] = j
    if posr == nxt[0]:
        if nxt[1] > posc:
            print("RIGHT")
        else:
            print("LEFT")
    elif posr < nxt[0]:
        print("DOWN")
    else:
        print("UP")

# Tail starts here

if __name__ == "__main__":
    pos = [int(i) for i in input().strip().split()]
    board = [[j for j in input().strip()] for i in range(5)]
    next_move(pos[0], pos[1], board)
