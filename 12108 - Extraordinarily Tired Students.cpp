
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
#include<map>
#include<iterator>

#define pf first
#define ps second
#define pii pair<int,int>
#define ll long long
#define mx 1000007
#define iscn()({ int a;scanf("%d",&a);a;})
#define liscn()({ ll a;scanf("%lld",&a);a;})
#define dscn()({ double a;scanf("%lf",&a);a;})
#define fi freopen("input.txt","r+",stdin)
#define fo freopen("output.txt","w+",stdout)
using namespace std;

/*............start.............*/
int _lcm(int a,int b)
{
    int i;
    if(a<b)
    {
        i=a;
        a=b;
        b=i;
    }
    i=1;
    while(i<b)
    {
        if( ((a*i)%b)==0)
            return (a*i);
        i++;
    }
    return (a*b);
}
int main()
{
    fi;
    fo;
    int n,i,j,k=0,lcm=1;
    while(n=iscn())
    {
    	int a[15],b[15],c[15],awk=0;
    	for(i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
            lcm=(_lcm(lcm,a[i]+b[i]));
            if(c[i]<=a[i])
                awk++;
        }
        for(j=1;j<=lcm ;j++)
        {
           // cout<<awk<<endl;
            if(awk==n)
                break;
            int awk_temp=0;       
            for(i=1;i<=n;i++)
            {

                
                if( ( (c[i])==(a[i]+b[i]) ) )
                {
                   
                    c[i]=0;
                    awk_temp++;
                }
                else if( ( c[i]==a[i] ) )
                {
                    if( (n-awk)>awk )
                        awk_temp--;
                    else
                        c[i]=0;
                }
                
                c[i]++;
            }

            awk+=awk_temp;
            
        }

        printf("Case %d: ",++k );
        if(awk==n)
            printf("%d\n",j);
        else
            printf("-1\n");
        
    }
    return 0;
}
