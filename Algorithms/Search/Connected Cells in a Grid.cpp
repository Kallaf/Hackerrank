#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> visited;
int n,m;

int dfs(int i,int j,vector<vector<int>>& matrix)
{
    if(visited[i][j])return 0;
    visited[i][j] = 1;
    int ans = 1;
    if(i>0 && matrix[i][j] == matrix[i-1][j]) ans += dfs(i-1,j,matrix);
    if(j>0 && matrix[i][j] == matrix[i][j-1]) ans += dfs(i,j-1,matrix);
    if(i<n-1 && matrix[i][j] == matrix[i+1][j]) ans += dfs(i+1,j,matrix);
    if(j<m-1 && matrix[i][j] == matrix[i][j+1]) ans += dfs(i,j+1,matrix);
    if(i>0 && j>0 && matrix[i][j] == matrix[i-1][j-1])ans += dfs(i-1,j-1,matrix);
    if(i>0 && j<m-1 && matrix[i][j] == matrix[i-1][j+1])ans += dfs(i-1,j+1,matrix);
    if(i<n-1 && j>0 && matrix[i][j] == matrix[i+1][j-1])ans += dfs(i+1,j-1,matrix);
    if(i<n-1 && j<m-1 && matrix[i][j] == matrix[i+1][j+1])ans += dfs(i+1,j+1,matrix);
    
    return ans;
}

// Complete the connectedCell function below.
int connectedCell(vector<vector<int>> matrix) {
    n = matrix.size();
    m = matrix[0].size();
    vector<bool> row(m,0);
    visited.assign(n,row);
    int ans = 0;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(!visited[i][j] && matrix[i][j] == 1)
        ans = max(ans,dfs(i,j,matrix));
        
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> matrix(n);
    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = connectedCell(matrix);

    fout << result << "\n";

    fout.close();

    return 0;
}
