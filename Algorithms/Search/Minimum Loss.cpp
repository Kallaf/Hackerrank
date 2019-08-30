#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumLoss function below.
long minimumLoss(vector<long> price) {
    vector<pair<long,int>> arr;
    for(int i=0;i<price.size();i++)
        arr.push_back({price[i],i});
    sort(arr.begin(),arr.end());
    long mn = INT_MAX;
    for(int i=1;i<arr.size();i++)
    {
        if(arr[i].second < arr[i-1].second)
            mn = min(mn,arr[i].first-arr[i-1].first);
    }
    return mn;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string price_temp_temp;
    getline(cin, price_temp_temp);

    vector<string> price_temp = split_string(price_temp_temp);

    vector<long> price(n);

    for (int i = 0; i < n; i++) {
        long price_item = stol(price_temp[i]);

        price[i] = price_item;
    }

    long result = minimumLoss(price);

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
