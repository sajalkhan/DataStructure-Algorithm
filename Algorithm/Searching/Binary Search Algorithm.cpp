#include<bits/stdc++.h>
#define max 50
using namespace std;
int main()
{
    int n;
    printf("How many number's do you need?\n");
    scanf("%d",&n);
    int a[max];
    printf("please enter your number:");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    printf("Array must be in sorted form\n");
    for(int i=0; i<n; i++)
        printf("%d ",a[i]);
    int key;
    printf("\nplease enter a number for search:");
    scanf("%d",&key);
    int start=0;
    int end=n-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(key==a[mid])
        {
            printf("%d found at position %d\n",key,mid+1);
            break;
        }
        else if(key<a[mid])
        {
            end=mid-1;
        }
        else if(key>a[mid])
        {
            start=mid+1;
        }
    }
    if(start>end)
    {
        printf("Nothing Found\n");
    }
}
