#include<stdio.h>

int main()
{
    char string[105];
    int n,k;
    scanf("%d%s%d",&n,string,&k);
    for(int i=0;i<n;i++)
        if(('A' <= string[i] && string[i] <= 'Z'))
        {
            char temp = string[i] - 'A';
            printf("%c",(temp+k)%26+'A');
        }
        else if(('a' <= string[i] && string[i] <= 'z'))
        {
            char temp = string[i] - 'a';
            printf("%c",(temp+k)%26+'a');
        }else
            printf("%c",string[i]);
    printf("\n");
    return 0;
}
