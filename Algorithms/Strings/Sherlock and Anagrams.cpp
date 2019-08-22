#include <iostream>

using namespace std;

int isAnagram(string s1,string s2)
{
    if(s1.length() != s2.length())return 0;
    int count1[30] = {0},count2[30] = {0};
    for(int i=0;i<s1.length();i++)
    {
        count1[s1[i]-'a']++;
        count2[s2[i]-'a']++;
    }
    for(int i=0;i<26;i++)
        if(count1[i]!=count2[i])return 0;
    return 1;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int count = 0;
        for(int len=1;len<s.length();len++)
        {
            for(int i=0;i<s.length()-len;i++)
            {
                string s1 = "";
                for(int j=i;j<i+len;j++)s1+=s[j];
                for(int j=i+1;j<s.length()-len+1;j++)
                {
                    string s2 = "";
                    for(int k=j;k<j+len;k++)s2 += s[k];
                    count += isAnagram(s1,s2);
                    //cout << s1 << " " << s2 << endl;
                }
            }
        }
        cout << count << endl;
    }
        
    return 0;
}
