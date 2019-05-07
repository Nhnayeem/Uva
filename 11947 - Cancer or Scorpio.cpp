#include<iostream>
using namespace std;
int day_month[13]={365,31,28,31,30,31,30,31,31,30,31,30,31};
int not_leapyear(int n)
{
    if(n%100)
    {
        return n%4;
    }
    else
    {
        return n%400;
    }
}
int month(int m,int y)
{
    if(m==2 && !not_leapyear(y))
        return 29;
    return day_month[m];

}
void zodiac(int d);

int main()
{
    int t,i,j,D,M,Y;
    cin>>t;

    for(i=1;i<=t;i++)
    {
        cin>>j;
        Y=j%10000;
        j=j/10000;
        D=j%100;
        j=j/100;
        M=j%100;
        for(j=0;j<280;j++)
        {
            D++;
            if(D>month(M,Y))
            {
                D=1;
                M++;
                if(M>12)
                {
                    M=1;
                    Y++;
                }
            }
        }
        cout<<i<<" ";
        if(M<10)    cout<<"0";
        cout<<M<<"/";
        if(D<10)    cout<<"0";
        cout<<D<<"/"<<Y<<" ";
        zodiac(M*100+D);
        cout<<endl;
    }
    return 0;
}
void zodiac(int d)
{
    if(d<=120)
        cout<<"capricorn";
    else if(d<=219)
        cout<<"aquarius";
    else if(d<=320)
        cout<<"pisces";
    else if(d<=420)
        cout<<"aries";
    else if(d<=521)
        cout<<"taurus";
    else if(d<=621)
        cout<<"gemini";
    else if(d<=722)
        cout<<"cancer";
    else if(d<=821)
        cout<<"leo";
    else if(d<=923)
        cout<<"virgo";
    else if(d<=1023)
        cout<<"libra";
    else if(d<=1122)
        cout<<"scorpio";
    else if(d<=1222)
        cout<<"sagittarius";
    else if(d<=1231)
        cout<<"capricorn";
}
