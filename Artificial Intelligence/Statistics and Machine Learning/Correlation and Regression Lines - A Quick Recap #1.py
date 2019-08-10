import math
def cov(x,y):
    xMean = sum(x)/len(x)
    yMean = sum(y)/len(y)
    sm = 0
    for i in range(0,len(x)):
        sm += x[i]*y[i]
    sm /= len(x)
    return sm - xMean*yMean

def standardDeviation(x):
    xPow2 = [i**2 for i in x]
    sm = sum(xPow2)/len(x)
    mean = (sum(x)/len(x))**2
    return math.sqrt(sm-mean)

x = [15,12,8,8,7,7,7,6,5,3]
y = [10,25,17,11,13,17,20,13,9,15]
print(round(cov(x,y)/(standardDeviation(x)*standardDeviation(y)),3))
