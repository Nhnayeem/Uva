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

#define ll long long
#define mx 1000007
#define iscn()({ int a;scanf("%d",&a);a;})
#define liscn()({ ll a;scanf("%lld",&a);a;})
#define dscn()({ double a;scanf("%lf",&a);a;})
#define fi freopen("input.txt","r+",stdin)
#define fo freopen("output.txt","w+",stdout)
using namespace std;

/*............start.............*/
vector<int> v[21];
int visit[21];
int level[21];
void clr()
{
    int i=21;
    while(i--)
    {
        v[i].clear();
    }
}
int bfs(int x,int y)
{
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
        it=v[tmp].begin();
        while(it!=v[tmp].end())
        {

            if(visit[*it]==-1)
            {

                visit[*it]=1;
                level[*it]=level[tmp]+1;
                if(*it==y)
                    return level[y];
                qu.push(*it);
            }
            it++;
        }


    }
    return 0;
}
int main()
{
    fi;
    fo;
    int i,t=0,n,x;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            x=iscn();
            v[1].push_back(x);
            v[x].push_back(1);
        }
        for(i=2; i<20; i++)
        {
            n=iscn();
            while(n--)
            {
                x=iscn();
                v[i].push_back(x);
                v[x].push_back(i);
            }

        }
        n=iscn();
        printf("Test Set #%d\n",++t);
        while(n--)
        {
            i=iscn(),x=iscn();
            cout.width(2);
            cout<<internal<<i<<" to ";
            cout.width(2);
            cout<<internal<<x<<": "<<internal<<bfs(i,x)<<endl;
        }
        printf("\n");
        clr();
    }
    return 0;
}
