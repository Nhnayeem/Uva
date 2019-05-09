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
int fx[]={1,-1,1,-1,2,-2,2,-2};
int fy[]={-2,2,2,-2,1,-1,-1,1};
int visit[9][9];
int level[9][9];
int h(char a)
{
    if(a>='a' && a<='h')
        return a-97;
    return a-49;
}
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
        for(int i=0;i<8;i++)
        {
            int u=f.pf+fx[i];
            int v=f.ps+fy[i];
            if(u>=0 && v>=0 && u<8 && v<8 && visit[u][v]==-1)
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
    fi;
    fo;
    char x1,x2,y1,y2;
    while(scanf("%c%c %c%c",&x1,&y1,&x2,&y2)!=EOF)
    {
        bfs(h(x1),h(y1));
        printf("To get from %c%c to %c%c takes %d knight moves.\n",x1,y1,x2,y2,level[h(x2)][h(y2)]);
        getchar();
    }
    return 0;
}
