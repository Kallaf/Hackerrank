#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long int

using namespace std;

vector<string> split_string(string);

bool isPrime[8200] = {0};
void setPrime(int x)
{
    for(int i=2;i*i<=x;i++)
        if(x%i == 0)return;
    isPrime[x] = true;
}

ll dp[1005][8200];
ll cnt[1005];

// Complete the primeXor function below.
int primeXor(vector<int> a) {
    memset(cnt,0,sizeof(cnt));
    memset(dp,0,sizeof(dp));
    for(int i=0;i<a.size();i++)
        cnt[a[i]-3500]++;
    dp[0][3500] = (cnt[0] + 1) / 2;
        dp[0][0] = (cnt[0] + 2) / 2;
        for(int i=1; i<=1000; i++){
            for(int j=0; j<=8191; j++){
                dp[i][j] = (dp[i-1][j]*((cnt[i]+2)/2) + dp[i-1][j^(i+3500)]*((cnt[i]+1)/2) ) % mod ;
            }
        }
        ll ans = 0;
        for(int i=0;i<=8191;i++){
            if(isPrime[i])
            (ans += dp[1000][i]) %= mod;
        }
        return ans;
}
int main()
{
    for(int i=2;i<=8200;i++)
        setPrime(i);
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
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

        int result = primeXor(a);

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
