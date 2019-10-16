#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
vector<int> primes;
bitset<100005> notPrime(0);

void setPrimes()
{

    for(int i=2;i<=100000;i++)
    {
        if(!notPrime.test(i))
        {
            for(int j=2*i;j<=100000;j+=i)
                notPrime.set(j);
            primes.push_back(i);
        }   
    }
}


// Complete the solve function below.
string solve(vector<int> a) {
    for(int prime:primes)
    {
        bool dividesAll = true;
        for(int x:a)
            if(x%prime)
            {
                dividesAll = false;
                break;
            }
        if(dividesAll)return "NO";
    }
    return "YES";
}

int main()
{
    setPrimes();
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int a_count;
        cin >> a_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string a_temp_temp;
        getline(cin, a_temp_temp);

        vector<string> a_temp = split_string(a_temp_temp);

        vector<int> a(a_count);

        for (int a_itr = 0; a_itr < a_count; a_itr++) {
            int a_item = stoi(a_temp[a_itr]);

            a[a_itr] = a_item;
        }

        string result = solve(a);

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
