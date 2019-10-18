#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long int
using namespace std;

int mulmod(ll a,ll b)
{
    ll res = 0;
    a = a%mod;
    while(b)
    {
        if(b&1)res = (res + a) % mod;
        a = (a*2) % mod;
        b >>= 1;
    }
    return res;
}

/*
 * Complete the summingSeries function below.
 */
int summingSeries(ll n) {
    return mulmod(n,n); 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        ll n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = summingSeries(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
