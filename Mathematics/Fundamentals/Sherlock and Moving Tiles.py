import math

def movingTiles(l, s1, s2, queries):
    r2 = math.sqrt(2)
    for qi in queries:
        if qi == (l**2):
            print("0.0000000")
        else:
            print("%.20f" % ((l-math.sqrt(qi))*r2/abs(s2-s1)))

if __name__ == '__main__':

    lS1S2 = input().split()

    l = int(lS1S2[0])

    s1 = int(lS1S2[1])

    s2 = int(lS1S2[2])

    queries_count = int(input())

    queries = []

    for _ in range(queries_count):
        queries_item = int(input())
        queries.append(queries_item)

    movingTiles(l, s1, s2, queries)
