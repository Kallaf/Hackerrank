#include <bits/stdc++.h>

using namespace std;

// Complete the candies function below.
long candies(int n, vector<int> arr) {
    if(arr.empty())return 0;
    vector<int> levels(n,1);
    long sum = 0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[i-1])
            levels[i] = levels[i-1]+1;
    }

    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]>arr[i+1])
        {
            if(i && arr[i]>arr[i-1])
                levels[i] = max(levels[i-1],levels[i+1]) + 1;
            else
                levels[i] = levels[i+1] +1;
        }
    }
    for(int i=0;i<n;i++)
        sum += levels[i];
        
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
