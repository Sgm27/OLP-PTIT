#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 50005
int f[maxn][26];
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    string s;
    cin>>s;
    s="#"+s;
    FOR(i,1,s.length()-1)
    {
        for (char c='a';c<='z';c++) f[i][c-97]=f[i-1][c-97];
        f[i][s[i]-97]++;
    }
    int q;
    cin>>q;
    while (q--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        bool flag=true;
        for (int x=0;x<=25;x++)
            if (f[b][x]-f[a-1][x]!=f[d][x]-f[c-1][x])
            {
                flag=false;
                break;
            }
        if (flag) cout<<"YES\n"; else cout<<"NO\n";
    }
}
