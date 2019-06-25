#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
vector<int> neighbors[100001];
bool visited[100001] = {0};

int dfs(int current)
{
    if(visited[current])return 0;
    visited[current] = 1;
    int ans = 1;
    for(auto neigbor:neighbors[current])
        ans += dfs(neigbor);
    return ans;
}

// Complete the journeyToMoon function below.
long journeyToMoon(int n, vector<vector<int>> astronaut) {

    for(auto pir:astronaut)
    {
        neighbors[pir[0]].push_back(pir[1]);
        neighbors[pir[1]].push_back(pir[0]);
    }

    vector<int> countries;
    for(int i=0;i<n;i++)
    {
        int temp = dfs(i);
        if (temp > 1)
            countries.push_back(temp);
    }
        

    long ans = long(n) * long(n-1);
    for(int i=0;i<countries.size();i++)
        ans -= long(countries[i] * (countries[i]-1));
    ans >>= 1;
    return ans;
}

/*
100000 2
1 2
3 4
output
4999949998
*/

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string np_temp;
    getline(cin, np_temp);

    vector<string> np = split_string(np_temp);

    int n = stoi(np[0]);

    int p = stoi(np[1]);

    vector<vector<int>> astronaut(p);
    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> astronaut[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = journeyToMoon(n, astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
