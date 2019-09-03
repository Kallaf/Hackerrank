#include <bits/stdc++.h>
#define ll long long int
#define pii pair<int,int> 
#define vi vector<int>
#define vs vector<string>
#define vpii vector<pii>
#define gt(x) cin >> x
#define gt2(n,k) cin >> n >> k
#define gt3(n,m,k) cin >> n >> m >> k
#define gtd(type,x) type x;gt(x)
#define gtp(type1,type2,x) type1 t1;type2 t2;cin >> t1 >> t2;x = {t1,t2};
#define tc gtd(int,t);while(t--)
#define gta(type,n,arr)type arr(n);loop(i,arr.size())gt(arr[i])
#define gtas(type,n,arr) gta(type,n,arr);srt(arr)
#define gtap(type1,type2,n,arr)vector<pair<type1,type2>> arr(n);loop(i,arr.size()){gtp(type1,type2,arr[i])}
#define gtaps(type1,type2,n,arr) gtap(type1,type2,n,arr);srt(arr)
#define gtapsd(type1,type2,n,arr) gtap(type1,type2,n,arr);srd(arr,pii)
#define loop(i,end) rpt(i,0,end)
#define rpt(i,start,end) for(int i=start;i!=end;i+=start<=end?1:-1)
#define srt(arr) sort(arr.begin(), arr.end())
#define srd(arr,type) sort(arr.begin(), arr.end(), greater<type>())
#define pr(x) cout << x << " "
#define prln(x) cout << x << endl

using namespace std;

int n,m,k;

// Write Code Here
//________________

int main()
{
    gt2(n,k);
    gtapsd(int,int,n,arr);
    int luck = 0;
    loop(i,n)
    {
        if(!arr[i].second)
            luck += arr[i].first;
        else if(k && arr[i].second)
        {
            luck += arr[i].first;
            k--;
        }else
            luck -= arr[i].first;
    }
    prln(luck);
    return 0;
}
