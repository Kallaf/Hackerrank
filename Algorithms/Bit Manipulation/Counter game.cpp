#include <bits/stdc++.h>

using namespace std;

// Complete the counterGame function below.
string counterGame(long n) {
    int count = 0, firstOne = -1, len=0;
    while (n) {
        if (n & 1)
        {
            count++;
            if (firstOne == -1)
                firstOne = len;
        }
        n >>= 1;
        len++;
    }
    return ((count - 1) + firstOne) % 2 ? "Louise" : "Richard";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = counterGame(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
