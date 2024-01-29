#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 100005
bool used[10];
set<int> se;
void Try(int i,int ans)
{
    if (i>=7) return;
    se.insert(ans);
    int st;
    if (i==1) st=1; else st=0; 
    FOR(j,st,5)
        if (!used[j])
        {
            used[j]=true;
            Try(i+1,ans*10+j);
            used[j]=false;
        }
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    fill(used,used+10,false);
    Try(1,0);
    vector<int> v(se.begin(),se.end());
    for (int x : v) cerr<<x<<" ";
    int tc; cin>>tc;
    while (tc--)
    {
        int l,r;
        cin>>l>>r;
        cout<<upper_bound(v.begin(),v.end(),r)-lower_bound(v.begin(),v.end(),l)<<"\n";	
    }
}
