#include<stdio.h>
int carry(int a,int b)
{
    int cnt=0,cry=0;
    while(1)
    {
        if(a==0 && b==0)
            break;
        cry=((a%10)+(b%10)+cry)/10;
        cnt=cnt+cry;
        a=a/10;
        b=b/10;
    }
    return cnt;
}
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        {
            if(a==0 && b==0)
                break;
        }
        if(carry(a,b)==0)
            printf("No carry operation.\n");
        else if(carry(a,b)==1)
            printf("1 carry operation.\n");
        else
            printf("%d carry operations.\n",carry(a,b));
    }
    return 0;
}
