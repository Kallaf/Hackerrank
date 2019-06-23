#include <stdio.h>

int main()
{
    int n;
    int loaves[1005];
    scanf("%d",&n);
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&loaves[i]);
        sum += loaves[i];
    }
    if(sum%2)
        printf("NO\n");
    else {
        int ans = 0,flag = 1;
        for(int i=0;i<n-1;i++)
        {
            if(loaves[i]%2)
            {
                loaves[i+1]++;
                ans += 2;
            }
        }
        printf("%d\n",ans);
    }

}
