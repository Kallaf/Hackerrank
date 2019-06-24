#include <bits/stdc++.h>

using namespace std;

// Complete the cavityMap function below.
vector<string> cavityMap(vector<string> grid) {
    vector<vector<char>> matrix;
    for(int i=0;i<grid.size();i++)
    {
        vector<char> row;
        for(int k=0;k<grid[i].size();k++)
        {
            if('0' <= grid[i].at(k) && grid[i].at(k) <= '9')
                row.push_back(grid[i].at(k));
        }
       matrix.push_back(row);
    }
    
    vector<string> ans;
    for(int i=0;i<grid.size();i++)
    {
        string row = "";
        for(int k=0,j=0;k<grid[i].size();k++)
        {
            int sum = 0;
            if('0' <= grid[i].at(k) && grid[i].at(k) <= '9')
            {
                if(i>0   && matrix[i][j] > matrix[i-1][j])sum++;
                if(j>0   && matrix[i][j] > matrix[i][j-1])sum++;
                if(i<matrix.size()-1 && matrix[i][j] > matrix[i+1][j])sum++;
                if(j<matrix[i].size()-1 && matrix[i][j] > matrix[i][j+1])sum++;
                j++;
            }
            if(sum == 4) row += 'X';
            else row += grid[i].at(k);
        }
       ans.push_back(row);
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = cavityMap(grid);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
