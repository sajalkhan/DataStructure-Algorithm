#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[50];
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<n;i++)
	{
		int value=a[i];
		int index=i;
		while(index>0 && a[index-1]>value)
		{
			a[index]=a[index-1];
			index--;
		}
		a[index]=value;
	}
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
