#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 100005
struct trie{
    int child[3];
    bool exist;
} t[maxn*4];
int n,nnode,q;
void add(string s)
{
    int node=0;
    for (char c : s)
    {
        int id=c-'a';
        if (!t[node].child[id]) t[node].child[id]=++nnode;
        node=t[node].child[id];
    }
    t[node].exist=1;
}
struct data{
    int Node,index,diff;
};
bool query(string s)
{
    int node=0;
    queue<data> Q;
    for (int i=0;i<=2;i++)
        if (t[node].child[i] && i != (s[0]-'a')) Q.push({t[node].child[i],1,1});
        else 
        if (t[node].child[i]) Q.push({t[node].child[i],1,0});
    while (!Q.empty())
    {
        int Node=Q.front().Node;
        int index=Q.front().index;
        int diff=Q.front().diff;
        if (index==s.length() && t[Node].exist && diff) return 1;
        Q.pop();
        int id=s[index]-'a';
        if (t[Node].child[id]) 
        {
            if (index<s.length()) 
                Q.push({t[Node].child[id],index+1,diff});
        }
        if (!diff)      
        {
            for (int i=0;i<=2;i++)
                if (i!=id && t[Node].child[i] && index<s.length()) 
                    Q.push({t[Node].child[i],index+1,diff+1});
        }
    }
    return 0;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>q;
    FOR(i,1,n)
    {
        string s; cin>>s;
        add(s);
    }
    while (q--)
    {
        string s; cin>>s;
        cout<<(query(s) ? "YES\n" : "NO\n");
    }
}
