#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long int
using namespace std;

// Complete the substrings function below.
int substrings(string n) {
    int l = n.length();
    vector<int> memo(l+5);
    memo[0] = 1;
    for(int i=1;i<l;i++)
        memo[i] = ((ll)memo[i-1] * 10 + 1) % mod;
    
    int sum = 0;
    for(int i=1;i<=l;i++)
    {
        int temp = ((ll)(n[i-1]-'0')*memo[l-i]) % mod;
        temp = ((ll) temp * i) % mod;
        sum = ((ll) sum + temp) % mod;
    }

    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n;
    getline(cin, n);

    int result = substrings(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
