#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 
int n,k;
int Next(int n,int k)
{
    FOR(i,1,k) n+=n%100;
    return n;
}
pair<int,string> get(int n)
{
    int num=Next(n,100);
    string s=to_string(num);
    while (s.length()<=3) s="0"+s;
    string start=s.substr(0,s.length()-3);
    string end=s.substr(s.length()-3,3);
    return {stoll(start),end};
}
void process()
{
    if (k<100) 
    {
        cout<<Next(n,k)<<"\n";
        return;
    }
    pair<int,string> ans=get(n);
    if (stoll(ans.second) % 100==0)  
    {
        if (ans.first != 0)
            cout<<ans.first<<ans.second<<"\n";
        else
            cout<<ans.second<<"\n";
        return;
    }
    int num=ans.first+5*(k/100-1);
    string N=to_string(num);
    N+=ans.second;
    cout<<Next(stoll(N),k%100)<<"\n";
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    // freopen("thu.out","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n>>k;
        process();	
    }
}