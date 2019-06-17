#include <stdio.h>

int main()
{
    int n,t;
    scanf("%d%d",&n,&t);
    int widths[100005];
    for(int i=0;i<n;i++)
        scanf("%d",&widths[i]);
    while(t--)
    {   
        int start,end,min=1000;
        scanf("%d%d", &start, &end);
        for(int i=start;i<=end;i++)
            if(widths[i]<min)min = widths[i];
        printf("%d\n",min);
    }
    return 0;
}
