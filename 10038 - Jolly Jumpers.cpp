#include<stdio.h>
int abs(int a)
{
    if(a<0)
        return a*-1;
    return a;
}
int main()
{
    int n,i;
    while(scanf("%d",&n)!=EOF)
    {
        int num[n],chek[n]={0};
        scanf("%d",&num[0]);
        for(i=1;i<n;i++)
        {
            scanf("%d",&num[i]);
            chek[abs(num[i]-num[i-1])]++;
        }
        for(i=1;i<n;i++)
        {
            if(chek[i]==0)
                break;
        }
        if(i>=n)
            printf("Jolly\n");
        else
            printf("Not jolly\n");

    }
    return 0;
}
