#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long int
using namespace std;

vector<vector<int>> childs;
vector<vector<int>> memo;

int helper(int n,int parent,bool eqParent)
{
    if(childs[n].size() == 1 && parent != -1)return eqParent;
    int ans = 1,sub=1;
    for(int child:childs[n])
    {
        if(child != parent)
        {
            if(memo[child][0] == -1)memo[child][0] = helper(child,n,0) % mod;
            if(memo[child][1] == -1)memo[child][1] = helper(child,n,1) % mod;
            int sum = (memo[child][0] + memo[child][1]) % mod ;
            ans = ((ll)ans*sum)%mod;
            sub = ((ll)sub*memo[child][0])%mod;
        }
    }
    if(!eqParent)ans = ((ll)ans+mod-sub) % mod;
    return ans;
}

// Complete the kingdomDivision function below.
int kingdomDivision(int n, vector<vector<int>> roads) {
    vector<int> temp(3,-1);
    memo.assign(n+5,temp);
    childs.resize(n+5);
    for(int i=0;i<roads.size();i++)
    {
        childs[roads[i][0]].push_back(roads[i][1]);
        childs[roads[i][1]].push_back(roads[i][0]);
    }
    return (2 * helper(roads[0][0],-1,0)) % mod;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> roads(n-1);
    for (int i = 0; i < n-1; i++) {
        roads[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> roads[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = kingdomDivision(n, roads);

    cout << result << "\n";
    return 0;
}
