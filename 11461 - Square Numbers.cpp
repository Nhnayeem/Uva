#include<stdio.h>
#include<math.h>
int scan(int* a,int* b)
{
    scanf("%d %d",a,b);
    return *a+*b;
}
int main()
{
    int a,b,i,c;
    while(scan(&a,&b))
    {
        c=0;
        i=(int)sqrt(a);
        while(i*i<a)
        {
            i++;
        }
        while(i*i<=b)
        {
            i++;
            c++;
        }
        printf("%d\n",c);
    }
}
