if __name__ == '__main__':
    x = int(raw_input())
    y = int(raw_input())
    z = int(raw_input())
    n = int(raw_input())

out = []
for i in range(0,x+1):
    for j in range(0,y+1):
        for k in range(0,z+1):
            if i+j+k != n:
                in_out = []
                in_out.append(i)
                in_out.append(j)
                in_out.append(k)
                out.append(in_out)

print out
