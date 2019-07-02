#!/usr/bin/python

# Head ends here

def next_move(posr, posc, board):
    if board[posr][posc] == 'd':
        board[posr][posc] = "_"
        print("CLEAN")
        return
    if posc != 0:
        for col in range(posc-1,-1,-1):
            if board[posr][col] == 'd':
                print("LEFT")
                return
    if posc != 4:
        for col in range(posc+1,5):
            if board[posr][col] == 'd':
                print("RIGHT")
                return
    print("DOWN")
    return
        

# Tail starts here

if __name__ == "__main__":
    pos = [int(i) for i in input().strip().split()]
    board = [[j for j in input().strip()] for i in range(5)]
    next_move(pos[0], pos[1], board)
