#include<bits/stdc++.h>
using namespace std;
void LCS(char*,char*);
int main()
{
	char s1[100],s2[100];
	gets(s1);
	gets(s2);
	LCS(s1,s2);
	return 0;
}
void LCS(char *s1,char *s2)
{
	int m=strlen(s1);
	int n=strlen(s2);
	int L[m+1][n+1];
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0 || j==0)
			{
				L[i][j]=0;
			}
			else if(s1[i-1]==s2[j-1])
			{
				L[i][j]=L[i-1][j-1]+1;
			}
			else
			{
				L[i][j]=max(L[i][j-1],L[i-1][j]);
//				L[i][j]=0;
			}
		}
	}
	printf("%d\n",L[m][n]);
	int i=m,j=n;
	int length=L[m][n];
	char lcs[length];
	while(i>0 && j>0)
	{
		if(s1[i-1]==s2[j-1])
		{
			lcs[length-1]=s1[i-1];
			i--,j--,length--;
		}
		else if(L[i-1][j]>L[i][j-1])
		{
			i--;
		}
		else j--;
	}
	puts(lcs);
}
