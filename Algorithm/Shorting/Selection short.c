/// Selection short... algorithom
#include<stdio.h>
#include<conio.h>
#define sajal 100
int main()
{
    system("color a");
    int i,j,n,m,num;
    int a[sajal];
    scanf("%d",&m);
    for(i=0; i<m; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Before Selection sort: ");
    for(i=0; i<m; i++)
    {
        printf("%d ",a[i]);
    }
    for(i=0; i<m-1; i++)
    {
        num=i;
        for(j=i+1; j<=m; j++)
        {
            if(a[j]<a[num])
                num=j;
        }
        int temp=a[i];
        a[i]=a[num];
        a[num]=temp;
    }
    printf("\n");
    printf("\nAfter selection sort : ");
    for(i=0; i<m; i++)
    {
        printf("%d ",a[i]);
    }
    getch();
    return 0;
}
