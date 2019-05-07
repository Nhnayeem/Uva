#include<stdio.h>
int main()
{
    int v,t,dis;
    while(scanf("%d%d",&v,&t)!=EOF)
    {
        dis=(v*t)*2;
        printf("%d\n",dis);
    }
    return 0;
}

