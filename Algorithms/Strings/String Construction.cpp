#include <bits/stdc++.h>
#include <bitset>

using namespace std;

// Complete the stringConstruction function below.
int stringConstruction(string s) {
    bitset<32> exist;
    for(int i=0;i<s.length();i++)
        exist[s[i]-'a'] = 1;
    int distinct = 0;
    for(int i=0;i<26;i++)if(exist[i])distinct++;
    return distinct;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = stringConstruction(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
