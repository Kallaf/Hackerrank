#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the anotherMinimaxProblem function below.
int anotherMinimaxProblem(vector<int> a) {
    int firstNotMatch = 0,match = 0;
    for(int i=31;i>=0;i--)
    {
        int first = a[0] >> i;
        for(int j=1;j<a.size();j++)
        {
            if(first != (a[j] >> i))
            {
                firstNotMatch = i;
                break;
            }
        }
        if (firstNotMatch == i)break;
        match += a[0] & (1 << i);
    }
    int ans = 2147483647, barrier = 1 << firstNotMatch;
    for(int i=0;i<a.size();i++)
    {
        if((a[i]-match) < barrier)
        {
          for (int j = i + 1; j < a.size(); j++)
            if ((a[j] - match) >= barrier)
              ans = min(a[i] ^ a[j], ans);
        }else{
          for (int j = i + 1; j < a.size(); j++)
            if ((a[j] - match) < barrier)
              ans = min(a[i] ^ a[j], ans);
        }
    }
    return ans == 2147483647?0:ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = anotherMinimaxProblem(a);

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
