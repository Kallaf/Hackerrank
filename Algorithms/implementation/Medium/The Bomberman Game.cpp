#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int R,C,n;
    vector<string> grid;

    cin >> R >> C >> n;

    for(int i=0;i<R;i++)
    {
        string input;
        cin >> input;
        grid.push_back(input);
    }


    vector<string> newState;
    vector<vector<int>> timer;
    for(int i=0;i<R;i++)
    {
        newState.push_back(grid[i]);
        vector<int> temp;
        temp.assign(C,0);
        for(int j=0;j<C;j++)
        {
            if(grid[i][j] == 'O')
                temp[j] = 1;
        }
        timer.push_back(temp);
    }
    if(n && n!=1)
    for(int t = 0;t<=(n+2)%4;t++)
    {
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                if(newState[i][j] == 'O')
                    timer[i][j]++;

        if(t%2)
        {
            for(int i=0;i<R;i++)
                for(int j=0;j<C;j++)
                {
                    if(grid[i][j] == 'O' && timer[i][j] == 3)
                    {
                        newState[i][j] = '.';
                        if(i>0)newState[i-1][j] = '.';
                        if(j>0)newState[i][j-1] = '.';
                        if(i<R-1)newState[i+1][j] = '.';
                        if(j<C-1)newState[i][j+1] = '.';
                    }
                }
        }else
        {
            for(int i=0;i<R;i++)
                for(int j=0;j<C;j++)
                    if(newState[i][j] == '.')
                    {
                        newState[i][j] = 'O';
                        timer[i][j] = 0;
                    }
        }
        for(int i=0;i<R;i++)
                for(int j=0;j<C;j++)
                    grid[i][j] = newState[i][j];

    }

    for(int i=0;i<R;i++)
        cout << newState[i] << endl;
    return 0;
}
