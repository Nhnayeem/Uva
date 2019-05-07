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

int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
int bomb[1001][1001];
int visit[1001][1001];
int level[1001][1001];
int R,C;
int bfs(int x,int y)
{
    pii p;
    queue<pii> q;
    memset(visit,-1,sizeof(visit));
    p.pf=x;
    p.ps=y;
    q.push(p);
    visit[x][y]=1;
    level[x][y]=0;
    while(!q.empty())
    {
        pii f=q.front();q.pop();
        pii t;
        for(int i=0;i<4;i++)
        {
            int u=f.pf+fx[i];
            int v=f.ps+fy[i];
            if(u>=0 && v>=0 && u<R && v<C && visit[u][v]==-1 && bomb[u][v]==-1)
            {
                visit[u][v]=1;
                level[u][v]=level[f.pf][f.ps]+1;
                t.pf=u;
                t.ps=v;
                q.push(t);
            }
        }
    }
    return 0;
}
int main()
{
    /*fi;
    fo;*/
    int i,N,n,r,c;
    while(1)
    {
        R=iscn(),C=iscn();
        if(R+C==0) break;
        N=iscn();
        memset(bomb,-1,sizeof(bomb));
        while(N--)
        {
            r=iscn();
            n=iscn();
            while(n--)
            {
                c=iscn();
                bomb[r][c]=1;
            }

        }
        r=iscn();c=iscn();
        n=iscn();N=iscn();
        bfs(r,c);
        cout<<level[n][N]<<endl;
    }
    return 0;
}
