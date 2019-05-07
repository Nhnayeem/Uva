#include<iostream>
#define fi freopen("input.txt","r+",stdin)
#define fo freopen("output.txt","w+",stdout)
using namespace std;
int main()
{
    //fi;
    //fo;
    int n;
    char xi,di,x,d,f;
    while(1)
    {
        cin>>n;
        if(n==0)
            break;
        f='x';
        x='x';
        d='+';
        n--;
        while(n--)
        {
            cin>>di>>xi;
            if(di!='N')
            {
                if(x=='x')
                {

                    f=xi;
                }
                if(f==xi)
                {
                    if(x=='x')
                    {
                        x=xi;
                        if(d=='+')
                            d=di;
                        else
                        {
                            if(di=='+')
                                d='-';
                            else
                                d='+';
                        }
                    }
                    else
                    {
                        x='x';
                        if(d=='+' && di=='+')
                            d='-';
                        else if(d=='+' && di=='-')
                            d='+';
                        else if(d=='-' && di=='+')
                            d='+';
                        else if(d=='-' && di=='-')
                            d='-';
                    }
                }
            }

        }
        cout<<d<<x<<endl;
    }
    return 0;
}

