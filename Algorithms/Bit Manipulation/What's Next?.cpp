#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<long> A;
        for(int i=0;i<n;i++)
        {
            long input;
            cin >> input;
            A.push_back(input);
        }
        if(n == 1)
            if(A[0]-1)
                cout << "3\n1 1 " << (A[0]-1) << endl;
            else
                cout << "2\n1 1\n";
        else if(n==2)
            if(A[0]-1)
                cout << "3\n1 " << (A[1]+1) << " " << (A[0]-1) << endl;
            else
                cout << "2\n1 " << (A[1]+1) << endl;
        else{
            if(n%2) // the last number is one
            {
                A[n-1]--;
                A[n-2]--;
                int m = n;
                if(A[n-2])m+=2;if(!A[n-1])m--;
                cout << m << endl;
                for(int i=0;i<n-3;i++)
                    cout << A[i] << " ";
                
                if(A[n-2])
                    cout << A[n-3] << " " << A[n-2] << " 1 1";
                else
                    cout << (A[n-3]+1) << " 1";
                if(A[n-1])cout << " " << A[n-1];
                cout << endl;

            }else // the last number is zero
            {
                    A[n-2]--;
                    A[n-3]--;
                    A[n-1]++;
                    int m=n;
                    if(!A[n-3])
                    {
                        A[n-4]++;
                        m--;
                    }else m++;
                    if(!A[n-2])
                        m--;
                    cout << m << endl;
                    for(int i=0;i<n-3;i++)
                        cout << A[i] << " ";
                    if(A[n-3])
                        cout << A[n-3] << " 1 ";
                    cout << A[n-1];
                    if(A[n-2])
                        cout << " " << A[n-2];
                    cout << endl;
        }
    }}
    return 0;
}
