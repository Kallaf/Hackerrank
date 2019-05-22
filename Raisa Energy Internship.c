//Dynamic programming solution

#include <stdio.h>
#include <string.h>
int count(char s[],int k)
{
	int n = strlen(s),counter=0;
	int dp[11][100002] = {0};
	for(int i=0;i<n;i++)
	{
		dp[s[i]-'0'][i]++;
		int flag = 1;
		for(int m=0;m<10;m++)
		{
			if(dp[m][i] && dp[m][i]!=k)
			{
				flag = 0;
				break;
			}
		}
		if(flag)counter++;
	}

	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			dp[s[j]-'0'][i]++;
			int flag = 1;
			for(int m=0;m<10;m++)
			{
				if(dp[m][i] && dp[m][i]!=k)
				{
					flag = 0;
					break;
				}
			}
			if(flag)counter++;
		}
	}

	return counter;
}

int main()
{
	int k;
	char s[100002];
	scanf("%s%d",s,&k);
	printf("%d\n",count(s,k));
	return 0;
}
