#include<iostream>

using namespace std;

int main()
{
    string mess;
    cin >> mess;
    int errors = 0;
    for(int i=0;i<mess.length();i++)
    {
        if(i%3 == 0 || i%3 == 2){if(mess[i]!='S')errors++;}
        else if(mess[i]!='O')errors++;
    }
    cout << errors << endl;
    return 0;
}
