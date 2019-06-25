#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,a,b;
        cin >> n >> a >> b;
        n--;
        vector<int> ans;
        int small = min(a,b),large = max(a,b);
        for(int i=0;i<=n;i++)
        {
            if(find(ans.begin(),ans.end(),(n-i)*small + i * large) == ans.end())
                ans.push_back((n-i)*small + i * large);
        }
        vector<int>::iterator it;
        for(it=ans.begin();it!=ans.end();++it)
            cout << *it << " ";
        cout << endl;
    }
    return 0;
}
