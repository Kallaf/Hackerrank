#include <bits/stdc++.h>

using namespace std;

// Complete the gameOfThrones function below.
string gameOfThrones(string s) {
    int count[30] = {0};
    for(int i=0;i<s.length();i++)
        count[s[i]-'a']++;
    int countOnes = 0;
    for(int i=0;i<26;i++)
    {
        if(count[i]%2)countOnes++;
        if(countOnes>1)return "NO";
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
