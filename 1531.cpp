#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 300005
string s;
int k,b,m;
int Pow[maxn],Hash[maxn];
int getHash(int i,int j)
{
    return (Hash[j]-Hash[i-1]*Pow[j-i+1]+m*m)%m;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>s>>k>>b>>m;
    int lenS=s.length();
    s=" "+s;
    // build POW
    Pow[0]=1;
    FOR(i,1,lenS) 
        Pow[i]=(Pow[i-1]*b)%m;
    // build Hash
    FOR(i,1,lenS)
        Hash[i]=(Hash[i-1]*b+s[i]-'0')%m;
    int ans=0;
    FOR(i,1,lenS-k+1)
        ans+=getHash(i,i+k-1);
    cout<<ans;
}
