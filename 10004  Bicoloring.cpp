#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
#include<iterator>

#define ll long long
#define mx 1000007
#define iscn()({ int a;scanf("%d",&a);a;})
#define liscn()({ ll a;scanf("%lld",&a);a;})
#define dscn()({ double a;scanf("%lf",&a);a;})
#define fi freopen("input.txt","r+",stdin)
#define fo freopen("output.txt","w+",stdout)
using namespace std;

/*............start.............*/
vector <int> a[200];
int color[200];
void clr()
{
    int i=200;
    while(i--)
    {
        a[i].clear();
    }
}
int bfs(int x)
{
    queue<int> qu;
    vector<int>::iterator it;
    qu.push(x);
    memset(color,-1,sizeof(color));
    color[x]=1;
    while(!qu.empty())
    {
        int tmp=qu.front();
        qu.pop();
        it=a[tmp].begin();
        while(it!=a[tmp].end())
        {
            if(color[*it]==-1)
            {
                /*color = 0 or 1 initialize*/
                color[*it]=(color[tmp]!=1);
                qu.push(*it);
            }
            else if(color[*it]==color[tmp])
                return 0;
            it++;
        }

    }
    return 1;
}
int main()
{
    /*fi;
    fo;*/
    int i,n,p,q,l;
    while(n=iscn())
    {
        clr();
        l=iscn();
        for(i=0;i<l;i++)
        {
            p=iscn(),q=iscn();
            a[p].push_back(q);
            a[q].push_back(p);
        }
        i=bfs(0);
        if(i)
            cout<<"BICOLORABLE."<<endl;
        else
            cout<<"NOT BICOLORABLE."<<endl;
    }
    return 0;
}
