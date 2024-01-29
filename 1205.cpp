#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 15
int n,m,k,color[maxn];
bool flag;
vector<int> adj[maxn];
bool check()
{
    FOR(i,1,n)
    {
        for (int x : adj[i]) 
            if (color[x]==color[i]) return false;
    }
    return true;
}
void Try(int i)
{
    if (flag) return;
    FOR(j,1,k) 
    {
        color[i]=j;
        if (i==n) 
        {
            if (check()) 
            {
                flag=true;
                return;
            }
        }
        else Try(i+1);
    }
}
signed main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        flag=false;
        cin>>n>>m>>k;
        FOR(i,1,n) adj[i].clear(), color[i]=0;
        FOR(i,1,m) 
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Try(1);
        if (flag) cout<<"YES\n"; else cout<<"NO\n";
    }    
}
