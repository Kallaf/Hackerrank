#include <iostream>

using namespace std;

int main()
{
    int n;string s;
    cin >> n >> s;
    int count[30] = {0};
    for(int i=0;i<n;i++)
        count[s[i]-'a']++;
    int mx = 0;
    for(char i='a';i<='z';i++)
    {
        if(count[i-'a'])
        {
           for(char j=i+1;j<='z';j++)
            {
                if(count[j-'a'])
                {
                    int len = 0;
                    char last = '0';
                    for(int c=0;c<n;c++)
                    {
                        if(s[c] == i || s[c] == j)
                        {
                            if(s[c] == last)
                            {
                                len = 0;
                                break;
                            }
                            last = s[c];
                            len++;
                        }
                    }
                    mx = max(mx,len);
                }
            } 
        }
    }
    cout << mx << endl;
    return 0;
}
