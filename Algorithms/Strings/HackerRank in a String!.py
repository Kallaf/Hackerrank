hackerrank = "hackerrank"
t = int(input())
for _ in range(t):
    string = input()
    i = 0
    for ch in string :
        if ch == hackerrank[i]:
            i+=1
            if i == 9:
                break
    if i == 9:
        print("YES")
    else:
        print("NO")
