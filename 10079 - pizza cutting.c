#include<stdio.h>
int main()
{
    int n,i;
    unsigned long int piece;
    while(scanf("%d",&n)!=EOF)
    {
        piece=1;
        if(n<0)
            break;
        for(i=1;i<=n;i++)
        {
            piece=piece+i;
        }
        printf("%lu\n",piece);
    }
    return 0;
}
