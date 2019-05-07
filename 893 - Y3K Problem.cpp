#include<iostream>
using namespace std;
int scan(int* n,int* d,int* m,int* y)
{
    cin>>*n>>*d>>*m>>*y;
    return *n+*d+*m+*y;
}
int months[13]={365,31,28,31,30,31,30,31,31,30,31,30,31};
int lmonths[13]={366,31,29,31,30,31,30,31,31,30,31,30,31};
int is_leapyear(int x)
{
    if(x%100!=0)
    {
        if(x%4==0)
            return 1;
        else
            return 0;
    }
    else
    {
        if(x%400==0)
            return 1;
        else
            return 0;
    }
}
void day_increase(int* n,int* d,int* m,int* y)
{
    int lp;
    if(is_leapyear(*y)==1)
        lp=lmonths[*m];
    else
        lp=months[*m];
    *d+=1;
    if(*d>lp)
    {
        *d=1;
        *m+=1;
        if(*m>12)
        {
            *m=1;
            *y+=1;
        }
    }
}

int main()
{
    int N,D,M,Y;
    while(scan(&N,&D,&M,&Y))
    {
        while(N>0 && M<=3)
        {
            day_increase(&N,&D,&M,&Y);
            N--;
        }
        while(N>365)
        {
            if(is_leapyear(Y+1)==1)
            {
                Y++;
                N=N-366;
            }
            else
            {
                Y++;
                N=N-365;
            }
        }
        while(N>0)
        {
            day_increase(&N,&D,&M,&Y);
            N--;
        }
        cout<<D<<" "<<M<<" "<<Y<<endl;
    }
    return 0;
}
