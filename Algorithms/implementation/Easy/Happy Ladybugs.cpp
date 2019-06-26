#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;string s;
        cin >> n >> s;
        bool yes = 1;
        int count = 1;
        char last = s.at(0);
        int counter[30] = {0};
        int under_score = 0;
        if(s.at(0) == '_')under_score++;
        else counter[s.at(0)-'A'] = 1;
        for(int i=1;i<n;i++)
        {
            if(s.at(i) == last)
            {
                count++;
            }
            else
            {
                if(count == 1)
                    yes = 0;
                last = s.at(i);
                count = 1;
            }
            if(s.at(i) == '_')under_score++;
            else counter[s.at(i)-'A']++;
        }
        if(count == 1)yes = 0;
        if(yes)cout << "YES\n";
        else {
            if(!under_score)cout << "NO\n";
            else {
                bool flag = 1;
                for(int i=0;i<26;i++)
                {
                    if(counter[i] == 1)
                    {
                        flag = 0;
                        break;
                    }
                }
                if(flag)cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }
    return 0;
}
