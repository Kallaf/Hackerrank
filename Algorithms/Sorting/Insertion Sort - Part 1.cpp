#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n+2);
    for(int i=0;i<arr.size();i++)
        cin >> arr[i];
    int last = arr[n-1];
    for(int i=n-1;i>=0;i--)
    {
        if(i == 0 || arr[i-1] < last)
        {
            arr[i] = last;
            break;
        }
        arr[i] = arr[i-1];
        cout << arr[0];
        for(int j=1;j<n;j++)
            cout << " " << arr[j];
        cout << endl;
    }
    cout << arr[0];
    for(int j=1;j<n;j++)
        cout << " " << arr[j];
    cout << endl;
    return 0;
}
