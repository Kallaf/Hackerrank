#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];

    for(int i=2;i<=n;i++)
    {
        sort(arr.begin(),arr.begin()+i);
        for(int j=0;j<n;j++)
            cout << arr[j] << " ";
        cout << endl;
    }
    return 0;
}
