#include<iostream>
#include<math.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define pii pair<int,int>
#define maxn 6
const int MOD=111539786;
int n,a[maxn],dp[31][31][31][31][31],id[30005];
void build_getID()
{
    FOR(i,1,30000) 
        if (i&1) id[i]=id[i-1]+1;
        else id[i]=id[i/2]+1; 
}
int calc(int a[])
{
    int ia[maxn]={};
    bool flag=false;
    FOR(i,1,n) 
    {
        ia[i]=id[a[i]];
        if (ia[i]) flag=true;
    }
    // FOR(i,1,n) cout<<a[i]<<" "; cout<<"\n";
    if (!flag) return 1;
    if (dp[ia[1]][ia[2]][ia[3]][ia[4]][ia[5]]!=-1) 
        return dp[ia[1]][ia[2]][ia[3]][ia[4]][ia[5]];
    int ans=0;
    FOR(i,1,n)
    {
        int j=(i+1<=n ? i+1 : 1);
        if (a[i]%2 && a[j]%2)
        {
            a[i]--,a[j]--;
            ans=(ans+calc(a))%MOD;
            a[i]++,a[j]++;
        }
    }
    
    FOR(i,1,n)
    {
        int j=(i+1<=n ? i+1 : 1);
        if (a[i] && a[j])
        {
            int b[maxn];
            FOR(i,1,n) b[i]=a[i];
            a[i]/=2,a[j]/=2;
            ans=(ans+calc(a))%MOD;   
            FOR(i,1,n) a[i]=b[i];
        }
    }
    dp[ia[1]][ia[2]][ia[3]][ia[4]][ia[5]]=ans;
    return ans;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    int Max=-1;
    FOR(i,1,n) cin>>a[i], Max=max(Max,a[i]);
    int LG=log2(Max);
    (LG*=2)+=1;
    FOR(i1,0,LG)
        FOR(i2,0,LG)
            FOR(i3,0,LG)
                FOR(i4,0,LG)
                    FOR(i5,0,LG) dp[i1][i2][i3][i4][i5]=-1;
    build_getID();
    cout<<calc(a);
}
