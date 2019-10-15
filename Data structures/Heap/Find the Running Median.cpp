#include <bits/stdc++.h>

using namespace std;

inline void print(float x)
{
    printf("%.1f\n",x);
}


int n;
int root=-1,ai;
int main()
{
    cin >> n;
    std::priority_queue <int> left;
    std::priority_queue <int, vector<int>, greater<int> > right; 

    while(n--)
    {
        cin >> ai;
        if(root == -1){
            root = ai;
            print(root);
        }else if(ai >= root)
        {
            if(right.size() > left.size())
            {
                left.push(root);
                right.push(ai);
                root = right.top();
                right.pop();
                print(root);
            }else if(right.size() < left.size())
            {
                right.push(ai);
                print(root);
            }else{
                right.push(ai);
                print((float)(root+right.top())/2.0);
            }

        }else
        {
            if(left.size() > right.size())
            {
                right.push(root);
                left.push(ai);
                root = left.top();
                left.pop();
                print(root);
            }else if(left.size() < right.size())
            {
                left.push(ai);
                print(root);
            }else{
                left.push(ai);
                print((float)(root+left.top())/2.0);
            }
        }
    }
    return 0;
}
