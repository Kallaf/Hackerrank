#include <bits/stdc++.h>

using namespace std;

// Complete the superReducedString function below.
string superReducedString(string s) {
    int n = s.length();bool updates = 1;
    while(updates)
    {
        updates = 0;
        for(int i=0;i<n-1;i++)
        {
            if(s.at(i) == s.at(i+1))
            {
                s.erase(i,2);
                n-=2;
                updates = 1;
            }
        }
    }
    
    if(s != "")return s;
    return "Empty String";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
