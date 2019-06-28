def nextMove(n,r,c,grid):
    pr = 0
    pc = 0
    for i in range(0,n):
        for j in range(0,n):
            if grid[i][j] == 'p':
                pr = i
                pc = j
    if c > pc:
        return "LEFT"
    if c < pc:
        return "RIGHT"
    if r > pr:
        return "UP"
    return "DOWN"

n = int(input())
r,c = [int(i) for i in input().strip().split()]
grid = []
for i in range(0, n):
    grid.append(input())

print(nextMove(n,r,c,grid))
