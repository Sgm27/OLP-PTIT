#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define bit(i,n) ((n>>i)&1)
#define set_on(i,n) ((n) | (1<<i))
#define set_off(i,n) ((n) & ~(1<<i)) 
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 1<<19
int n,mod,a[19],count_digit[10],fact[20];
int dp[1<<18][100];
string s;
inline void init_fact()
{
    fact[0]=1;
    for (int i=1;i<=18;i++) fact[i]=i*fact[i-1];
}
inline void process()
{
    for (int i=0;i<(1<<n);i++)
        for (int j=0;j<mod;j++) dp[i][j]=0;
    dp[0][0]=1;
    for (int i=0;i<n;i++)
        if (a[i] != 0) dp[1<<i][a[i]%mod]=1;
    for (int mask=1;mask<(1<<n);mask++)
    {
        for (int x=0;x<mod;x++)
        {
            if (!dp[mask][x]) continue;
            for (int k=0;k<n;k++)
                if (bit(k,mask)==0)
                {
                    int new_mask=set_on(k,mask);
                    int new_mod=(x*10+a[k])%mod;
                    dp[new_mask][new_mod]+=dp[mask][x];
                }
        }
    }
    int answer=dp[(1<<n)-1][0];
    for (int i=0;i<=9;i++) answer/=fact[count_digit[i]];
    cout<<answer<<"\n";
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    init_fact();
    int tc; cin>>tc;
    while (tc--)
    {
        memset(count_digit,0,sizeof(count_digit));
        cin>>n>>mod;
        int idx=-1;
        while (n)
        {
            a[++idx] = n%10;
            count_digit[a[idx]]++;
            n /= 10;
        }
        n=idx+1;
        process();
    }
    cerr<<TIME;
}
