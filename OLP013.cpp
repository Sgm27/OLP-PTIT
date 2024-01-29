#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 
int P,Q,s,t;
int Pow(int a, int n,int mod)
{
    if (!n) return 1%mod;
    if (n==1) return a%mod;
    int tmp=Pow(a,n/2,mod)%mod;
    tmp=tmp*tmp%mod;
    if (n%2) tmp=tmp*a%mod;
    return tmp;
}
void sub1_sub2()
{
    int ans=0;
    P %= Q;
    FOR(i,1,t)
    {
        P *= 10;
        if (i>=s) ans += P/Q;
        P %= Q;
    }
    ans %= Q;
    cout<<ans<<"\n";
}
void sub3()
{
    P %= Q;
    unordered_map<int,int> d;
    vector<int> number;
    number.push_back(-1);
    int idx=0;
    do 
    {
        d[P]=++idx;
        P *= 10;
        number.push_back(P/Q);
        P %= Q;
    }
    while (!d[P]);
    // for (int c : number) cerr<<c<<" "; cerr<<"\n";
    int start_cycle=d[P],len_cycle=number.size()-start_cycle;
    int sum_cycle=0,answer=0;
    FOR(i,start_cycle,number.size()-1) sum_cycle += number[i];
    // cerr<<sum_cycle<<" "<<start_cycle<<"\n";
    if (t<=start_cycle) 
        FOR(i,s,t) answer += number[i];
    else
    {
        if (s<start_cycle) 
        {
            FOR(i,s,start_cycle-1) answer += number[i];
            s=start_cycle;
        }
        int st_point=(t-start_cycle)/len_cycle;
        int ed_point=(s-start_cycle)/len_cycle;
        int num_cycle=st_point - ed_point - 1;
        answer += max(0ll,num_cycle*sum_cycle);
        // cout<<answer<<"\n";
        int st_idx=(s-start_cycle)%len_cycle+start_cycle;
        int ed_idx=(t-start_cycle)%len_cycle+start_cycle;
        if (st_point != ed_point)
        {
            FOR(i,st_idx,number.size()-1) answer += number[i];
            FOR(i,start_cycle,ed_idx) answer += number[i];
        }
        else
            FOR(i,st_idx,ed_idx) answer += number[i];
        // cout<<answer;
    }
    answer %= Q;
    cout<<answer<<"\n";
}
void sub4()
{
    // cong thuc
    // ans=P*10^(k-1) % Q la so truoc do
    // -> dap so la ans*10/Q
    P%=Q;
    int pre_ans=P*Pow(10,s-1,Q)%Q;
    int answer=((pre_ans*10)/Q)%Q;
    cout<<answer<<"\n";
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>P>>Q>>s>>t;
        if (t<=100) sub1_sub2();
        else 
        if (P<=100 && Q<=100) sub3();
        else sub4(); 	
    }
}
