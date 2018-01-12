#include<stdio.h>
#include<math.h>
int main()
{
    int t,n,i,j,k;
    int flag;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        scanf("%d",&n);
        flag=1;
        for(j=2; j<=sqrt(n); j++)
        {
            if(n%j==0)
            {
                printf("Not Prime\n");
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            printf("Prime\n");
        }
    }
    return 0;
}
