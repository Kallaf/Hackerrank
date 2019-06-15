#include <stdio.h>

#define MOD 1000000007

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,input,ans = 0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&input);
            ans |= input;
        }

        n--;
        while(n--)
            ans = (ans << 1) % MOD;
        printf("%d\n",ans);
    }
    return 0;
}
