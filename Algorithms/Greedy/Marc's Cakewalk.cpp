#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define gt(n) scanf("%d",&n)
#define gtll(n) scanf("%lld",&n)
#define gtA(arr)for(int i=0;i<arr.size();i++)gt(arr[i])
#define gtAll(arr)for(int i=0;i<arr.size();i++)gtll(arr[i])
#define sortA(arr) sort(arr.begin(), arr.end())
#define sortD(arr) sort(arr.begin(), arr.end(), greater<int>())
#define prLn(n) printf("%d\n",n)
#define prLnll(x) printf("%lld\n",x)

using namespace std;

int main()
{
    int n;
    gt(n);
    vi calorie(n);
    gtA(calorie);
    sortD(calorie);
    ll walk = 0;
    for(ll i=0;i<calorie.size();i++)
        walk += (1ll<<i) * (ll)calorie[i];
    prLnll(walk);
    return 0;
}
