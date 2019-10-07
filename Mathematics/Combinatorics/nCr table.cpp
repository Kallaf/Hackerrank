#include <bits/stdc++.h>
#define mod 1000000000
using namespace std;


int t,n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //---------------------------
    int pascalTri[1000][1000] = {0};
    for(int i=0;i<1000;i++)
        pascalTri[i][0] = 1;
    for(int n=1;n<1000;n++)
        for(int r=1;r<=n;r++)
            pascalTri[n][r] = (pascalTri[n-1][r-1] + pascalTri[n-1][r]) % mod;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int r=0;r<=n;r++)
            cout << pascalTri[n][r] << " ";
        cout << endl;
    }
    return 0;
}
