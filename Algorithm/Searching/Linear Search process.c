/// Liner search.......
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 50
int main()
{
    system("color a");
    int a[max],i,n,m,key;
    while(1)
    {
        printf("\t\t\tPress (1) For work\n");
        printf("\t\t\tPress (2) For Exit\n");
        scanf("%d",&m);
        system("cls");
        if(m==1)
        {
        printf("Enter how many numbers do you need?\n");
        scanf("%d",&n);
        system("cls");
        printf("enter your number\n");
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            system("cls");
        }
        printf("Search any number\n");
        scanf("%d",&key);
        for(i=0;i<n;i++)
        {
            if(a[i]==key)
            {
                break;
            }
        }
        if(i==n)///(i==n) means i 0 theke n porjonto sob number search korce and i er value n er soman hoye gese

        {
            printf("Nothing Found !!\n\n\n");
        }
        else
            printf("%d is found at position %d\n\n\n",key,i+1);
        }
        if(m==2)
        {
            exit(1);
        }
    }
    return 0;
}
