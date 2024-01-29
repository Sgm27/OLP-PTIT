#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 
string s,t;
int l[6]={3,0,2,4,1,5};
int r[6]={0,4,1,3,5,2};
unordered_map<string,int> D;
string move_left(string s)
{
    string ans="";
    FOR(i,0,5)
        ans+=s[l[i]];
    return ans;
}
string move_right(string s)
{
    string ans="";
    FOR(i,0,5)
        ans+=s[r[i]];
    return ans;
}
void bfs(string s,string t)
{
    queue<string> Q;
    Q.push(s);
    D[s]=0;
    while (!Q.empty())
    {
        string x=Q.front();
        Q.pop();
        string st=move_left(x);
        if (!D[st])
        {
            Q.push(st);
            D[st]=D[x]+1;
        }
        if (st==t) return;
        st=move_right(x);
        if (!D[st])
        {
            Q.push(st);
            D[st]=D[x]+1;
        }
        if (st==t) return;
    }
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; tc=1;
    while (tc--)
    {
        s=t="";
        FOR(i,1,6)
        {
            int x; cin>>x;
            s+=x+'0';
        }
        FOR(i,1,6)
        {
            int x; cin>>x;
            t+=x+'0';
        }
        bfs(s,t);
        cout<<D[t]<<"\n";
        D.clear();
    }
}
