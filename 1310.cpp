#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 1003
int n,k,a[maxn];
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
        int tmp=n,pos=-1;
        FOD(i,k,1) 
            if (a[i]!=tmp--) 
            {
                pos=i;
                break;
            }
        if (pos==-1)
        {
            FOR(i,1,k) cout<<i<<" ";
        }
        else
        {
            a[pos]+=1;
            int cnt=0;
            FOR(i,pos+1,k) a[i]=a[pos]+(++cnt);
            FOR(i,1,k) cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
}
