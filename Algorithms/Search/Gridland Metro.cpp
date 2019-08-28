#include <bits/stdc++.h>
#define ll long long int

using namespace std;

vector<string> split_string(string);

vector<vector<ll>> merge(vector<vector<ll>>& intervals) {
        sort(intervals.begin(),intervals.end());
    vector<vector<ll>> newIntervals;
    if(intervals.empty())return newIntervals;
    int index = 0;
    newIntervals.push_back(intervals[0]);
    for(int i=1;i<intervals.size();i++)
    {
        if(intervals[i][0] <= newIntervals[index][1])
            newIntervals[index][1] = max(intervals[i][1],newIntervals[index][1]);
        else{
            newIntervals.push_back(intervals[i]);
            index++;
        }
    }
    return newIntervals;
}

// Complete the gridlandMetro function below.
ll gridlandMetro(ll n, ll m, int k, vector<vector<ll>> track) {
    sort(track.begin(),track.end());
    ll busy = 0;
    if(!track.empty())
    {
        ll curr_row = track[0][0];
        vector<vector<ll>> intervals;
        for(int i=0;i<k;i++)
        {
            if(track[i][0] != curr_row)
            {
                curr_row = track[i][0];
                vector<vector<ll>> new_intervals = merge(intervals);
                for(int j=0;j<new_intervals.size();j++)
                    busy += new_intervals[j][1] - new_intervals[j][0] + 1;
                intervals.clear();
            }
            vector<ll> interval;
            interval.push_back(track[i][1]);
            interval.push_back(track[i][2]);
            intervals.push_back(interval);
        }
        vector<vector<ll>> new_intervals = merge(intervals);
        for(int j=0;j<new_intervals.size();j++)
            busy += new_intervals[j][1] - new_intervals[j][0] + 1;
    }
    return n*m-busy;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nmk_temp;
    getline(cin, nmk_temp);

    vector<string> nmk = split_string(nmk_temp);

    int n = (ll)stoi(nmk[0]);

    int m = (ll)stoi(nmk[1]);

    int k = (ll)stoi(nmk[2]);

    vector<vector<ll>> track(k);
    for (int i = 0; i < k; i++) {
        track[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> track[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    ll result = gridlandMetro(n, m, k, track);

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
