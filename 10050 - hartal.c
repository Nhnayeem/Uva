#include<stdio.h>
int hartalday(int *hp,int day,int lenth)
{
    int i,r=0;
    for(i=0;i<lenth;i++)
    {
        if(day%hp[i]==0)
        {
            r=1;
        }
    }
    return r;
}
int main()
{
    int i,T,n,h,days=0;
    int hp[100];
    scanf("%d",&T);
    while(T--)
    {
        days=0;
        scanf("%d",&n);
        scanf("%d",&h);
        for(i=0;i<h;i++)
        {
            scanf("%d",&hp[i]);
        }
        for(i=1;i<=n;i++)
        {
            if((((i+1)%7)!=0) && ((i%7)!=0))
            {
                if(hartalday(hp,i,h)==1)
                    days++;
            }
        }
        printf("%d\n",days);
    }
    return 0;
}
