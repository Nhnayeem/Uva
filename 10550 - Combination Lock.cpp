#include<stdio.h>
int clock(int x,int y)
{
    if(y>x)
        return (40-(y-x));
    return (x-y);

}
int anticlock(int x,int y)
{
    if(x>y)
        return (40-(x-y));
    return (y-x);
}
int scan(int* H,int* U,int* D,int* F)
{
    scanf("%d %d %d %d",H,U,D,F);
    return (*H+*U+*D+*F);
}
int main()
{
    int i,a,b,c,D;
    while(scan(&i,&a,&b,&c))
    {
        D=1080+clock(i,a)*9+anticlock(a,b)*9+clock(b,c)*9;
        printf("%d\n",D);
    }
    return 0;
}

