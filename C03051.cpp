#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" ms"
#define int long long
#define pii pair<int,int>
#define maxn 1000006
vector<int> tprime;
int prime[maxn];
void eratos()
{
    FOR(i,1,maxn-6) prime[i]=1;
    prime[0]=prime[1]=0;
    FOR(i,2,sqrt(maxn-6))
        if (prime[i])
            for (int j=i*i;j<=(maxn-6);j+=i) prime[j]=0;
    FOR(i,1,maxn-6) 
        if (prime[i]) tprime.push_back(i*i);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    eratos();
    int tc; cin>>tc;
    while (tc--)
    {
        int l,r;
        cin>>l>>r;
        cout<<upper_bound(tprime.begin(),tprime.end(),r)-lower_bound(tprime.begin(),tprime.end(),l)<<"\n";	
    }
}
