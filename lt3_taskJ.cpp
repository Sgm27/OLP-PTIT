#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 105
int n,a[maxn];
int SUM;
map<int,int> d;
int dd[maxn][maxn];
void Try(vector<pair<int,vector<int>>> v,vector<vector<int>> ans)
{
    if (v.size()==1) 
    {
        int dem[15]={};
        for (auto v : ans)
            for (auto it : v) 
            {                                                                                          
                d[it]++;
                dem[it]++;
            }
        for (int i=0;i<n;i++) 
        {
            // cout<<dem[i]<<" ";
            dd[dem[i]][i]++;
        }
        // cout<<"\n";
    }
    for (int i=0;i<v.size()-1;i++)
    {
        vector<pair<int,vector<int>>> tmp=v;
        int tong=v[i].first+v[i+1].first;
        vector<int> t=v[i].second;
        for (int k : v[i+1].second) t.push_back(k); 
        tmp.erase(tmp.begin()+i);
        tmp.erase(tmp.begin()+i);
        tmp.insert(tmp.begin()+i,{tong,t});
        ans.push_back(t);
        Try(tmp,ans);
        ans.pop_back();
    }
}
void process()
{
    vector<pair<int,vector<int>>> v(n);
    FOR(i,0,n-1)
    {
        v[i].first=a[i];
        v[i].second.push_back(i);
    }
    Try(v,{});
    vector<int> vt;
    for (auto it : d) cout<<it.second<<" ", vt.push_back(it.second); cout<<"\n";
    for (int i=1;i<vt.size();i++)
        cout<<vt[i]-vt[i-1]<<" ";
    int sum=0;
    for (auto it : d) 
        sum+=a[it.first]*it.second;
    for (int i=0;i<n;i++)
    {
        for (int j=1;j<=n;j++) cout<<dd[j][i]<<" ";
        cout<<"\n";
    }
    cout<<sum;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    freopen("thu.out","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n;
        FOR(i,0,n-1) cin>>a[i];
        process();
    }
}
