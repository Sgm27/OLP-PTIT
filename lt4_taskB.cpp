#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 205 
string s[maxn];
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    cin.ignore();
    while (tc--)
    {
        string st;
        getline(cin,st);
        stringstream ss(st);
        string tmp;
        int idx=0;
        while (ss >> tmp) s[++idx]=tmp;
        string tat="";
        FOR(i,1,idx)
            if (s[i]!="and" && s[i]!="of" && s[i]!="in") tat+=toupper(s[i][0]);
        cout<<tat<<" "<<st<<"\n";
    }
}
