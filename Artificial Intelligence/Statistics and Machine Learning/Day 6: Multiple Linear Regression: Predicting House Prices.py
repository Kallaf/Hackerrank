from sklearn.linear_model import LinearRegression

arr = list(map(int,input().split()))
F = arr[0]
R = arr[1]
X = []
Y = []
for _ in range(R):
    arr = list(map(float,input().split()))
    X.append(arr[:F])
    Y.append(arr[F])

model = LinearRegression().fit(X, Y)

t = int(input())
x = []
for _ in range(t):
    x.append(list(map(float,input().split())))

results = model.predict(x)
for y_pred in results:
    print(round(y_pred,2))
