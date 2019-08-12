from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import PolynomialFeatures

arr = list(map(int,input().split()))
F = arr[0]
R = arr[1]
X = []
Y = []
for _ in range(R):
    arr = list(map(float,input().split()))
    X.append(arr[:F])
    Y.append(arr[F])

polynomial_features= PolynomialFeatures(degree=3)
x_poly = polynomial_features.fit_transform(X)
model = LinearRegression().fit(x_poly, Y)

t = int(input())
x = []
for _ in range(t):
    x.append(list(map(float,input().split())))

x_poly = polynomial_features.fit_transform(x)
results = model.predict(x_poly)
for y_pred in results:
    print(round(y_pred,2))
