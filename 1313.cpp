#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 1005
int n,a[maxn],k;
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
        cin>>n>>k;
        FOR(i,1,k) cin>>a[i];
        int tmp=k,pos=-1;
        FOD(i,k,2) 
            if (a[i]!=a[i-1]+1) 
            {
                pos=i;
                break;
            }
        if (pos==-1 && a[1]==1) 
            FOR(i,n-k+1,n) cout<<i<<" ";
        else
        {
            a[pos]--;
            if (a[k]!=n) FOR(i,pos+1,k) a[i]++;
            FOR(i,1,k) cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
}
