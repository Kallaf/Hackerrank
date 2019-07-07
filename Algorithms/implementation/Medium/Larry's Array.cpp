#include<iostream>
#include<vector>

using namespace std;

int countConv(vector<int> arr)
{
    int n = arr.size(),conv = 0;
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(arr[i] > arr[j])conv++;
    return conv;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin >> arr[i];
        int conv = countConv(arr);
        if(conv%2)cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
