#include <bits/stdc++.h>

using namespace std;

int t,n;

int main()
{   
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << (n%7 > 1?"First":"Second") << endl;
    }
    return 0;
}
