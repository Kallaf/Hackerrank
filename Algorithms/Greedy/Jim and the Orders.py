n = int(input())
s = []
for i in range(n):s.append([sum(list(map(int, input().rstrip().split()))),i+1])
s.sort()
for row in s:print(row[1],end=' ')
print()
