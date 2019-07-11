#include<iostream>

using namespace std;

int main()
{
    int n;
    string password;
    cin >> n >> password;
    int lw = 0,up = 0,nums=0,sp = 0;
    for(int i=0;i<n;i++)
    {
        if('a' <= password[i] &&  password[i] <= 'z')
            lw++;
        else if('A' <= password[i] &&  password[i] <= 'Z')
            up++;
        else if('0' <= password[i] &&  password[i] <= '9')
            nums++;
        else
            sp++;
    }
    int needed = (lw?0:1) + (up?0:1) + (nums?0:1) + (sp?0:1);
    int ans = needed;
    if(n+needed < 6)ans = 6-n;
    cout << ans << endl;
    return 0;
}
