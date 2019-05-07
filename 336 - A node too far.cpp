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
vector<int> a[mx];
int visit[mx];
int level[mx];
int nods[mx];
void clr()
{
    int i=mx;
    while(i--)
    {
        a[i].clear();
    }
}
int bfs(int x,int y)
{
    int visited=0;
    queue<int> qu;
    vector<int>::iterator it;
    qu.push(x);
    memset(visit,-1,sizeof(visit));
    visit[x]=1;
    level[x]=0;
    while(!qu.empty())
    {
        int tmp=qu.front();
        qu.pop();
        if(level[tmp]<y)
        {
            it=a[tmp].begin();
            while(it!=a[tmp].end())
            {

                if(visit[*it]==-1)
                {

                    visit[*it]=1;
                    level[*it]=level[tmp]+1;
                    visited++;
                    qu.push(*it);
                }
                it++;
            }
        }

    }
    return visited;
}
int main()
{
    /*fi;
    fo;*/
    int i,p,q,t=0,n,nod;
    while(n=iscn())
    {
        clr();
        nod=0;
        memset(nods,-1,sizeof(nods));
        for(i=0; i<n; i++)
        {
            p=iscn(),q=iscn();
            a[p].push_back(q);
            a[q].push_back(p);
            if(nods[p]==-1)
            {
                nods[p]=1;
                nod++;
            }
            if(nods[q]==-1)
            {
                nods[q]=1;
                nod++;
            }
        }

        while(1)
        {
            p=iscn(),q=iscn();
            if(p==0 && q==0)
                break;
            i=bfs(p,q);
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++t,nod-i-1,p,q);
        }
    }
    return 0;
}

