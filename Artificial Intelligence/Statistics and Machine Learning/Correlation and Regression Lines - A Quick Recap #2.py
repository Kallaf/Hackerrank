def slope(x,y):
    n = len(x)
    z = [a*b for a,b in zip(x,y)]
    num = n*sum(z)-sum(x)*sum(y)
    x2 = [a**2 for a in x]
    dem = n*sum(x2)-sum(x)**2
    return round(num/dem,3)

PhysicsScores = [15,12,8,8,7,7,7,6,5,3]
HistoryScores = [10,25,17,11,13,17,20,13,9,15]

print(slope(PhysicsScores,HistoryScores))
