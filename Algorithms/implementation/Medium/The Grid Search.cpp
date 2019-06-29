#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int R,C;
        cin >> R >> C;
        vector<string> G(R+1);
        for(int i=0;i<R;i++)
            cin >> G[i];
        int r,c;
        cin >> r >> c;
        vector<string> P(r+1);
        for(int i=0;i<r;i++)
            cin >> P[i];
        bool yes = 0;
        for(int ii=0;ii<R-r+1;ii++)
        {
            for(int jj=0;jj<C-c+1;jj++)
            {
                int count = 0;
                for(int i=0,iii=ii;i<r;i++,iii++)
                {
                    for(int j=0,jjj=jj;j<c;j++,jjj++)
                    {
                        if(G[iii][jjj] != P[i][j])
                            goto out1;
                        count++;
                    }
                }
                out1:
                    if(count == r*c)
                    {
                        yes = 1;
                        goto out2;
                    }
            }
        }
        out2:
        printf("%s\n",yes?"YES":"NO");
    }
    return 0;
}
