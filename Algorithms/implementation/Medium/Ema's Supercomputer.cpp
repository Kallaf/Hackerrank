#include<iostream>
#include<vector>
using namespace std;

class Plus{
    public:
        pair<int,int> center;
        int length,n,m,area;
        Plus(pair<int,int> _center,int _length,int _n,int _m)
        {
            center = _center;
            length = _length;
            n = _n;m = _m;
            area = 1 + 4 * length;
        }

        bool overlap(Plus other)
        {
            vector<vector<bool>> grid(n);
            for(int i=0;i<n;i++)
                grid[i].assign(m,0);
            for(int i=center.first-length;i<=center.first+length;i++)
                grid[i][center.second] = true;
            for(int j=center.second-length;j<=center.second+length;j++)
                grid[center.first][j] = true;

            for(int i=other.center.first-other.length;i<=other.center.first+other.length;i++)
                if(grid[i][other.center.second])return true;
            for(int j=other.center.second-other.length;j<=other.center.second+other.length;j++)
                if(grid[other.center.first][j])return true;
            
            return false;
        }
};

int main()
{
    int h,w;
    cin >> h >> w;
    char matrix[505][505];
    vector<Plus> pluses;
    for(int i=0;i<h;i++)
        scanf("%s",matrix[i]);
    
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(matrix[i][j] == 'G')
            {
                int up = 0,down=0,left=0,right=0;
                    for(int x=i-1;x>=0;x--)
                        if(matrix[x][j] == 'G')
                            up++;
                        else
                            break;
                    for(int x=j-1;x>=0;x--)
                        if(matrix[i][x] == 'G')
                            left++;
                        else
                            break;
                    for(int x=i+1;x<h;x++)
                        if(matrix[x][j] == 'G')
                            down++;
                        else
                            break;
                    for(int x=j+1;x<w;x++)
                        if(matrix[i][x] == 'G')
                            right++;
                        else
                            break;
                    int len = min(min(left,right),min(up,down));
                    for(int x=len;x>=0;x--)
                        pluses.push_back(Plus(make_pair(i,j),x,h,w));
            }
        }
    }
    
    int ans = 0;
    for(int i=0;i<pluses.size()-1;i++)
        for(int j=i+1;j<pluses.size();j++)
            if(!pluses[i].overlap(pluses[j]))
                ans = max(pluses[i].area*pluses[j].area,ans);

    cout << ans << endl;
    
    return 0;
}
