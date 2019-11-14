#include <bits/stdc++.h>

using namespace std;

int digitsSum(int x)
{
    int sum = 0;
    while(x)
    {
        sum += x%10;
        x/=10;
    }
    return sum;
}

// Complete the solve function below.
int solve(int n) {
    int sum = digitsSum(n);
    for(int i=2;i*i<n;i++)
    {
        if(n%i == 0)
        {
            int digits = digitsSum(i);
            while(n%i == 0)
            {
                sum -= digits;
                if(sum < 0)return 0;
                n/=i;
            }
        }
    }
    if(n != 1){
        sum -= digitsSum(n);
    }
    return !sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = solve(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
