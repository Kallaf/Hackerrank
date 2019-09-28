#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> memo;

bool helper(int ia,int ib,string a,string b)
{
    if(a.size() - ia < b.size() - ib)return false;
    if(ia == a.size() && ib == b.size())return true;
    if(ib == b.size())
    {
        for(int i=ia;i<a.size();i++)
            if(isupper(a[i]))return false;
        return true;
    }
    if(memo[ia][ib] != -1)return memo[ia][ib];
    if(isupper(a[ia]))
    {
        if(a[ia] != b[ib])
            return false;
        return helper(ia+1,ib+1,a,b);
    }
    a[ia] = toupper(a[ia]);
    return memo[ia][ib] = helper(ia+1,ib,a,b) || helper(ia,ib,a,b);
}

// Complete the abbreviation function below.
string abbreviation(string a, string b) {
    vector<int> temp(b.length()+5,-1);
    memo.assign(a.length()+5,temp);
    return helper(0,0,a,b)?"YES":"NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
