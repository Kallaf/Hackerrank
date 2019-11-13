#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the solve function below.
int solve(int x1, int y1, int x2, int y2) {
    return __gcd(abs(x1-x2),abs(y1-y2))-1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string x1Y1X2Y2_temp;
        getline(cin, x1Y1X2Y2_temp);

        vector<string> x1Y1X2Y2 = split_string(x1Y1X2Y2_temp);

        int x1 = stoi(x1Y1X2Y2[0]);

        int y1 = stoi(x1Y1X2Y2[1]);

        int x2 = stoi(x1Y1X2Y2[2]);

        int y2 = stoi(x1Y1X2Y2[3]);

        int result = solve(x1, y1, x2, y2);

        fout << result << "\n";
    }

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
