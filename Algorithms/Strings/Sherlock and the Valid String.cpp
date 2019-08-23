#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    int count[30] = {0};
    for(int i=0;i<s.length();i++)
        count[s[i]-'a']++;
    int x1=0,x2=0,cx1=0,cx2=0;
    for(int i=0;i<26;i++)if(count[i])
    {
        if(!x1)
        {
            x1 = count[i];
            cx1++;
        }
        else if(!x2)
        {
            if(count[i] != x1)
            {
                x2 = count[i];
                cx2++;
            }else cx1++;
        }else
        {
            if(count[i]!=x1 && count[i]!=x2)return "NO";
            if(count[i] == x1)cx1++;
            if(count[i] == x2)cx2++;
        }
        
        if(x1 && x2)
        {
            if(x1 == 1 && cx1 == 1)continue;
            if(x2 == 1 && cx2 == 1)continue;
            if(abs(x1-x2)!=1) return "NO";
            if(x1 > x2 && cx1  > 1)return "NO";
            if(x2 > x1 && cx2  > 1)return "NO";
        }
        
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
