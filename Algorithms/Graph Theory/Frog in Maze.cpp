#include<iostream>
#include<cmath>
#include<vector>

const long double EPS=1e-9;

using namespace std;

int n,m,k,sx,sy;
char maze[25][25];
bool visited[25][25] = {0};
pair<int,int> tunnels[25][25];
bool isTunnel[25][25] = {0};
long double a[405][405] = {0};
long double C[405] = {0};
int N = 0;
int idx[25][25];
int index(int x,int y)
{
    if(idx[x][y]==-1)
    {
        idx[x][y] = N;
        N++;
    }
    return idx[x][y];
}

int type(int x,int y)
{
    if(x<0 || y<0 || x>=n || y>=m || maze[x][y] == '#')return 0;
    if(maze[x][y] == 'O' || maze[x][y] == 'A')return 1;
    if(maze[x][y] == '*')return 2;
    if(maze[x][y] == '%')return 3;
    return -1;
}

void dfs(int px,int py)
{
    if(type(px,py) != 1 || visited[px][py])return;
    visited[px][py]=1;
    int z = index(px,py);
    int x = px,y=py;
    if(isTunnel[x][y])
    {
        x = tunnels[px][py].first;
        y = tunnels[px][py].second;
    }
    long double h=0;
    if(type(x-1,y))h++;
    if(type(x,y-1))h++;
    if(type(x+1,y))h++;
    if(type(x,y+1))h++;

    if(h == 0)
    {
        a[z][z] = 1;
        return;
    }
    a[z][z] = h;

    if(type(x-1,y) == 3)C[z]++;
    if(type(x,y-1) == 3)C[z]++;
    if(type(x+1,y) == 3)C[z]++;
    if(type(x,y+1) == 3)C[z]++;
    
    if(type(x-1,y) == 1)a[z][index(x-1,y)]=-1;
    if(type(x,y-1) == 1)a[z][index(x,y-1)]=-1;
    if(type(x+1,y) == 1)a[z][index(x+1,y)]=-1;
    if(type(x,y+1) == 1)a[z][index(x,y+1)]=-1;

    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y-1);
    dfs(x,y+1);
}

vector<long double> gauss (vector < vector<long double> > a) {
    vector<int> where (N, -1);
    for (int col=0, row=0; col<N && row<N; ++col) {
        int sel = row;
        for (int i=row; i<N; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (abs (a[sel][col]) < EPS)
            continue;
        for (int i=col; i<=N; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<N; ++i)
            if (i != row) {
                long double c = a[i][col] / a[row][col];
                for (int j=col; j<=N; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }
    vector<long double> ans(N, 0);
    for (int i=0; i<N; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][N] / a[where[i]][i];
    return ans;
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)
        scanf("%s",maze[i]);
    for(int i=0;i<k;i++)
    {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        x1--;y1--;x2--;y2--;
        isTunnel[x1][y1] = true;isTunnel[x2][y2] = true;
        tunnels[x1][y1] = make_pair(x2,y2);tunnels[x2][y2] = {x1,y1};
    }
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)
    {
        if(maze[i][j] == 'A'){sx = i;sy = j;}
        idx[i][j] = -1;
    }

    dfs(sx,sy);
    bool noExit = true;
    for(int i=0;i<N;i++)if(C[i]){noExit = false;break;}
    if(noExit){
        printf("0\n");
        return 0;
    }
    vector<vector<long double> > A;
    A.resize(N);
    for(int i=0;i<N;i++)
    {
        A[i].resize(N+1);
        for(int j=0;j<N;j++)A[i][j]=a[i][j];
        A[i][N]=C[i];
    }
    vector<long double> P = gauss(A);
    cout << P[0] << endl;
    return 0;
}
