#include<bits/stdc++.h>
#define max 100
using namespace std;
void merge(int *a,int *L,int Llength,int *R,int Rlength)
{
	int i,j,k;
	i=0,j=0,k=0;
	while(i<Llength && j<Rlength)
	{
		if(L[i]<R[j])a[k++]=L[i++];
		else a[k++]=R[j++];
	}
	while(i<Llength)a[k++]=L[i++];
	while(j<Rlength)a[k++]=R[j++];
}
void mergsort(int *a,int n)
{
	int *L,*R,mid;
	if(n<2)return;
	mid=n/2;
	L=(int*)malloc(mid*sizeof(int));
	R=(int*)malloc((n-mid)*sizeof(int));
	for(int i=0;i<mid;i++)L[i]=a[i];
	for(int i=mid;i<n;i++)R[i-mid]=a[i];
	mergsort(L,mid);
	mergsort(R,n-mid);
	merge(a,L,mid,R,n-mid);
	free(L);
	free(R);
}
int main()
{
	int a[max],n;
	cout<<"how many number's do you want to add?"<<endl;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	mergsort(a,n);
	for(int i=0;i<n;i++) printf("%d ",a[i]);
	return 0;
}
