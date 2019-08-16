#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<tuple<int,int,string>> arr;
    for(int i=0;i<n/2;i++)
    {
        int index;string temp;
        cin >> index >> temp;
        arr.push_back(make_tuple(index,i,"-"));
    }
    for(int i=n/2;i<n;i++)
    {
        int index;string temp;
        cin >> index >> temp;
        arr.push_back(make_tuple(index,i,temp));
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++)
        cout << get<2>(arr[i]) << " ";
    cout << endl;
    return 0;
}
