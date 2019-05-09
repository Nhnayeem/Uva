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
map<string,vector<string>> root;
map<string,int> visit;
map<string, string> parent;
int bfs(string a,string b)
{
    vector<string>::iterator it;
    queue<string> qu;
    qu.push(a);
    visit[a]=1;
    while(!qu.empty())
    {
        string t;
        t=qu.front();
        qu.pop();
        for ( it = root[t].begin() ; it!=root[t].end() ; it++ )
        {
            if ( visit.count(*it) == 0 )
            {
                qu.push(*it);
                visit[*it]=1;
                parent[*it]=t;
                if(*it == b)
                    return 1;
            }
        }
    }
    return 0;
}
int main()
{
    fi;
    fo;
    int n;
    bool fst=true;
    string a,b;
    while(scanf("%d ",&n)!=EOF)
    {
        root.clear();
        visit.clear();
        parent.clear();
        for (int i = 0; i < n; ++i)
        {
            cin>>a>>b;
            root[a].push_back(b);
            root[b].push_back(a);
            
        }
        cin>>a>>b;
        if(!fst)    cout<<endl;
        fst=false;
        if(bfs(a,b)==1)
        {                
            stack<string> stk;
            while(1)
            {
                stk.push(b);
                stk.push(parent[b]);
                if(stk.top()==a)
                    break;
                b=parent[b];    
            }
            while(!stk.empty())
            {
                cout<<stk.top()<<" ";
                stk.pop();
                cout<<stk.top()<<endl;
                stk.pop();
            }
        }
        else
        {
            cout<<"No route"<<endl;
        }

    }
    return 0;
}
