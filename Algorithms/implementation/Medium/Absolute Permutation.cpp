#include<iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        if (k && (n%k || n/k%2)) 
        {
            cout << "-1" << endl;
            continue;
        }
        if(!k)for(int i=1;i<=n;i++)if(i==1)cout<< i;else cout << " " << i;
        else
            for(int i=1;i<=n;i+=(k<<1))
            {
                for (int j = i + k; j < i + (k<<1); j++)
                    if(j == 1+k)cout << j;else cout << " " << j;
                for (int j = i; j < i + k; j++)
                    cout << " " << j;
            }
        cout << endl;
    }
    return 0;
}
