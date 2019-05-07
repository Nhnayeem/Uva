#include<stdio.h>
void dizcout(int n,int* a)
{
    if(n==0)
        return;
    a[(n%10)]+=1;
    return dizcout(n/10,a);
}
int main()
{
    int N,t,i;
    scanf("%d",&N);
    while(N--)
    {
        int diz[10]={0};
        scanf("%d",&t);
        for(i=1;i<=t;i++)
        {
            dizcout(i,diz);
        }
        for(i=0;i<9;i++)
        {
            printf("%d ",diz[i]);
        }
        printf("%d\n",diz[9]);
    }
    return 0;
}
