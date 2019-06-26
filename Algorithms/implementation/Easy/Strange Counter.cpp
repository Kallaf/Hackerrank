#include <bits/stdc++.h>

using namespace std;

// Complete the strangeCounter function below.
long strangeCounter(long t) {
    long time = 1,p_time;
    long value=3;
    for(time=1;t>time;value <<= 1){
        p_time = time;
        time += value;
    }
    cout << (value/2) << " " << p_time ;
    if(time == t)return value;
    return value/2 - (t - p_time); 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    long t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = strangeCounter(t);

    fout << result << "\n";

    fout.close();

    return 0;
}
