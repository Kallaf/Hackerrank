#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vs vector<string>
#define gt(x) cin >> x
#define gtd(type,x) type x;gt(x)
#define tc gtd(int,t);while(t--)
#define gta(type,n,arr)type matrix(n);rpt(i,0,arr.size())gt(arr[i])
#define loop(i,end) rpt(i,0,end)
#define rpt(i,start,end) for(int i=start;i!=end;i+=start<=end?1:-1)
#define srt(arr) sort(arr.begin(), arr.end())
#define srd(arr,type) sort(arr.begin(), arr.end(), greater<type>())
#define pr(x) cout << x << " "
#define prln(x) cout << x << endl

using namespace std;

// Write Code Here
//________________

int main()
{
    tc{
        gtd(int,n);
        gta(vs,n,matrix);
        loop(i,n) srt(matrix[i]);
        loop(j,n)rpt(i,1,n)if(matrix[i][j] < matrix[i-1][j])goto NO;
        prln("YES");
        continue;
        NO:prln("NO");
    }
    return 0;
}
