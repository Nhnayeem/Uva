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
vector<string> dic;
map<string,int> visit;
map<string,int> level;
int cmpr(string a,string b)
{
    int c=0;
    for(int i=0;i<a.length();i++)
        if (a[i]!=b[i])
            c++;
    if(c==1)    return 1;
    return 0;
}
int bfs(string a,string b)
{
    queue<string> qu;
    qu.push(a);
    visit.clear();
    visit[a]=1;
    level[a]=0;
    while(!qu.empty())
    {
        string t;
        t=qu.front();
        qu.pop();
        vector<string>::iterator it;
        for (it=dic.begin();it!=dic.end();it++)
        {
            string s=*it;
            if(t.length()==s.length())
            {
                if ( visit.count(s) == 0 && cmpr(t,s)==1)
                {
                    qu.push(s);
                    visit[s]=1;
                    level[s]=level[t]+1;
                    if(s == b)
                        return level[b];
                }                
            }
            
        }
    }
    return level[b];
}
int main()
{
    fi;
    fo;
    int n;
    bool fst=true;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {   
        dic.clear();
        visit.clear();
        level.clear();
        string a,b;
        while(1)
        {
            cin>>a;
            if(a[0]=='*') break;
            dic.push_back(a);
        }
      //  bool t=false;
        char c;
        while(cin>>a>>b)
        {
            getchar();
            cout<<a<<" "<<b<<" "<<bfs(a,b)<<endl;
            c=getchar();
            if(c=='\n')
            {
                cout<<endl;
                break;
            } 
            else
                cin.putback(c);
        }
    }
    return 0;
}
