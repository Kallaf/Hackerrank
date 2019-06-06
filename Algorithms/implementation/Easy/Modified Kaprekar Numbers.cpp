#include <bits/stdc++.h>

#define ll long long int

using namespace std;

bool isKaprekar(ll n) {
    ll temp = n, d = 0;
    while (temp) {
        temp /= 10;
        d++;
    }
    ll pow2 = n*n;
    ll r = pow2 % (ll)pow(10, d);
    ll l = pow2 / (ll)pow(10, d);
    if (l + r == n)
        return true;
    return false;
}

// Complete the kaprekarNumbers function below.
void kaprekarNumbers(ll p, ll q) {
    bool flag = 1;
    for (ll i = p; i <= q; i++)
        if (isKaprekar(i)) {
            printf("%lld ", i);
            flag = false;
        }
    if(flag)
        printf("INVALID RANGE");
    printf("\n");
}

int main()
{
    ll p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    ll q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    kaprekarNumbers(p, q);

    return 0;
}
