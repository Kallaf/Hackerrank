#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int q,t,x;
stack<int> s1;
stack<int> s2;

void enqueue()
{
    s1.push(x);
}

void dequeue()
{
    if(s2.empty())
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    if(!s2.empty())
        s2.pop();
}

void print()
{
    if(s2.empty())
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    if(!s2.empty())
        cout << s2.top() << endl;

}

int main() {
    cin >> q;
    while(q--)
    {
        cin >> t;
        switch(t)
        {
            case 1:
                cin >> x;
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            default:
                print();
        }
    }
    return 0;
}
