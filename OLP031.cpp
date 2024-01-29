#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
const int N=1e7;
#define maxn 
vector<int> prime;
int Isprime[N+5];
void eratos()
{
    Isprime[0]=Isprime[1]=1;
    FOR(i,1,sqrt(N))
        if (!Isprime[i])
            for (int j=i*i;j<=N;j+=i) Isprime[j]=1;
    FOR(i,1,N)
        if (!Isprime[i]) prime.push_back(i);
}
void solve(int n)
{
    int idx=0;
    while (n!=1 && prime[idx]<=sqrt(n))
    {
        int cnt=0;
        while (n%prime[idx]==0) cnt++, n/=prime[idx];
        if (cnt) 
            cout<<prime[idx]<<" "<<cnt<<"\n";
        idx++;
    }
    if (n!=1) cout<<n<<" "<<1<<"\n";
}
signed main()
{
    #ifndef ONLINE_JUDGE
    // freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    eratos();
    int tc; tc=1;
    while (tc--)
    {
        int n;
        cin>>n;
        solve(n);	
        cout<<"\n";
    }
    cerr<<"Time elapsed : "<<(double)clock()/1000<<" ms";
}