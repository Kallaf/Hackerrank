
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    int n,t,x,top=-1;
    cin >> n;
    int arr[100005];
    stack<int> mx;
    while(n--)
    {
        cin >> t;
        if(t == 1){
            cin >> x;
            arr[++top] = x;
            if(mx.empty() || mx.top() <= x)mx.push(x);
        }else if(t==2)
            {if(mx.top() == arr[top--])mx.pop();}
        else
            cout << mx.top() << endl;
    }
    return 0;
}
