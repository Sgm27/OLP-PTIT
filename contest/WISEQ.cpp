#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" ms"
#define int long long
#define pii pair<int,int>
#define maxn 50004
int n,s,a[maxn],t[maxn*4],dp[maxn],ans,b[maxn],sum[maxn];
void update(int id,int l,int r,int p,int val)
{
    if (l>p || r<p) return;
    if (l==r) return t[id]=max(t[id],val), void();
    int m=(l+r)/2;
    update(id*2,l,m,p,val);
    update(id*2+1,m+1,r,p,val);
    t[id]=max(t[id*2],t[id*2+1]);
}
int get(int id,int l,int r,int u,int v)
{
    if (r<u || l>v) return 0;
    if (l>=u && r<=v) return t[id];
    int m=(l+r)/2;
    int t1=get(id*2,l,m,u,v);
    int t2=get(id*2+1,m+1,r,u,v);
    return max(t1,t2);
}   
void sub1()
{
    FOR(i,1,n)
    {
        dp[i]=1, sum[i]=a[i];
        FOR(j,1,i-1) 
            if (a[j]<a[i] && sum[j]+a[i]<=s) 
            {
                if (dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                    sum[i]=sum[j]+a[i];
                }
                else
                if (dp[i]==dp[j]+1)
                    sum[i]=min(sum[i],sum[j]+a[i]);
            }
        ans=max(ans,dp[i]);
    }
    cout<<ans;
}
void sub2()
{
    FOR(i,1,n)
    {
        dp[i]=get(1,1,n,1,a[i]-1)+1;
        update(1,1,n,a[i],dp[i]);
        ans=max(ans,dp[i]);
    }
    cout<<ans;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>s;
    FOR(i,1,n) cin>>a[i];
    if (n<=500) sub1(); else sub2();
}
