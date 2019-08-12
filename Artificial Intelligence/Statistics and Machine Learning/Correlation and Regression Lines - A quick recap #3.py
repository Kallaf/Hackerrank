from statistics import mean

def best_fit_slope_and_intercept(xs,ys):
    zs = [a*b for a,b in zip(xs,ys)]
    x2 = [a**2 for a in xs]
    m = (((mean(xs)*mean(ys)) - mean(zs)) /
         ((mean(xs)*mean(xs)) - mean(x2)))
    
    b = mean(ys) - m*mean(xs)
    
    return m, b

xs = [15,12,8,8,7,7,7,6,5,3]
ys = [10,25,17,11,13,17,20,13,9,15]
m, b = best_fit_slope_and_intercept(xs,ys)

y = m * 10 + b
print(round(y,1))

