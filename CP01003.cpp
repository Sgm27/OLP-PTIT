#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
#define maxn 
#define limit 1000000000
vector<int> v,nt;
int d[4]={2,3,5,7};
bool nto(int k)
{
    if (k==2 || k==3) return 1;
    if (k<2 || k%2==0 || k%3==0) return 0;
    int i=5;
    while(i<=sqrt(k))
    {
        if (k%i==0 || k%(i+2)==0) return 0;
        i+=6;
    }
    return 1;
}
bool tong_nto(int s)
{
    int sum=0;
    while (s)
    {
        sum+=s%10;
        s/=10;
    }
    return nto(sum);
}
void init()
{
    queue<int> Q;
    FOR(i,0,3) Q.push(d[i]), v.push_back(d[i]);
    while (!Q.empty())
    {
        int x=Q.front();
        Q.pop();
        FOR(i,0,3)
        {
            int t=x*10+d[i];
            if (t<limit) 
            {
                Q.push(t);
                if (d[i]==3 || d[i]==7) 
                    if (tong_nto(t) && nto(t)) v.push_back(t); 
            }
        }
    }
    // cout<<v.size()<<"\n";
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    init();
    int tc; cin>>tc;
    while (tc--)
    {
        int l,r;
        cin>>l>>r;
        cout<<upper_bound(v.begin(),v.end(),r)-lower_bound(v.begin(),v.end(),l)<<"\n";	
    }
    cerr<<TIME;
}
