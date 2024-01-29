#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
const ll MOD=1e9+7;
const int base=31;
ll Hash[maxn],Pow[maxn],n,k;
string s;
void build_pow()
{
    Pow[0]=1;
    for (int i=1;i<=maxn-3;i++)
        Pow[i]=(Pow[i-1]*base)%MOD;
}
void build_hash()
{
    for (int i=1;i<=n;i++)
        Hash[i]=(Hash[i-1]*base+s[i]-'a'+1)%MOD;
}
ll getHash(int l,int r)
{
    return (Hash[r]-Hash[l-1]*Pow[r-l+1]+MOD*MOD)%MOD;
}
int f(int x)
{
    unordered_map<ll,int> mp;
    int Max=0;
    for (int i=1;i<=n-x+1;i++)
    {
        ll tmp=getHash(i,i+x-1);
        mp[tmp]++;
        Max=max(Max,mp[tmp]);
    }
    return Max;
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    build_pow();
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n>>k;
        cin>>s;
        s=" "+s;
        build_hash();
        int l=0,r=1500;
        while (r-l>1)
        {
            int m=(l+r)/2;
            if (f(m)>=k) l=m;
            else r=m;
        }
        cout<<l<<"\n";	
    }
}