#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 35
int a[maxn],n,S,sum,flag,ans=INT_MAX;
void Try(int i,int s,int cnt)
{
    if (s>S || i>n || flag) return;
    if (s==S)
    {
        flag=1;
        ans=cnt;
        return;
    }
    Try(i+1,s+a[i],cnt+1);
    Try(i+1,s,cnt);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>S;
    FOR(i,1,n) cin>>a[i], sum+=a[i];
    if (sum<S) return cout<<"-1", 0;
    sort(a+1,a+1+n,greater<int>());
    Try(1,0,0);
    if (flag) cout<<ans;
    else cout<<"-1";
}
