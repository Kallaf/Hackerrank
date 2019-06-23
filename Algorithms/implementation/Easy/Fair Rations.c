#include <stdio.h>

int main()
{
    int n,reminder = 0,input,ans = 0;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {    
        scanf("%d",&input);
        if((input+reminder)%2)
        {
            ans += 2;
            reminder = 1;
        }else 
            reminder = 0;
    }
    scanf("%d",&input);
    if((input+reminder)%2)
        printf("NO\n");
    else 
        printf("%d\n",ans);

}
