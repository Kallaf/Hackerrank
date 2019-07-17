#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n,shifts = 0;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    for (int i = 1; i < n; i++) 
    {  
        int key = arr[i],j = i - 1;  
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;
            shifts++;  
        }  
        arr[j + 1] = key;  
    } 
    cout << shifts << endl;
    return 0;
}
