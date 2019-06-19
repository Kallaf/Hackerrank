#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n,m;
    cin >> n >> m;
    vector<int> current,previous(n+5);
    for(int i=0;i<n;i++)
    {
        int input;
        cin >> input;
        current.push_back(input);
    }
    for(long bit=0;bit<64;bit++)
    {
         
        if((m-1)&(1l<<bit))
        {
            for(long i=0;i<n;i++)
                previous[i] = current[i]^current[(i+(1l<<bit))%n];
            for(long i=0;i<n;i++)
                current[i] = previous[i];
        }
    }
    for(long i=0;i<n;i++)
        cout << current[i] << " ";
    cout << endl;
    return 0;
}
