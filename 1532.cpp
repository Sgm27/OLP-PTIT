#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 100005
int n,a[maxn],sum,d[15];
vector<int> MOD[3];
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
        bool flag=false;
        memset(d,0,sizeof(d));
        cin>>n;
        sum=0;
        FOR(i,1,n) cin>>a[i], MOD[a[i]%3].push_back(a[i]), sum+=a[i], d[a[i]]++;
        sort(a+1,a+1+n);
        FOR(i,0,2) sort(MOD[i].begin(),MOD[i].end());
        if (sum%3==0)
        {
            FOD(i,n,1) cout<<a[i];
            flag=true;
        }
        else
        if (sum%3==1)
        {
            if (MOD[1].size()) 
            {
                d[MOD[1][0]]--;
                FOD(i,9,0)
                    while (d[i]) 
                    {
                        cout<<i, d[i]--;
                        flag=true;
                    }
            }
            else 
            if (MOD[2].size()>=2)
            {
                d[MOD[2][0]]--;
                d[MOD[2][1]]--;
                FOD(i,9,0)
                    while (d[i]) 
                    {
                        cout<<i, d[i]--;
                        flag=true;
                    }          
            }
        }
        else
        {
            if (MOD[2].size())
            {
                d[MOD[2][0]]--;
                FOD(i,9,0)
                    while (d[i]) 
                    {
                        cout<<i, d[i]--;
                        flag=true;
                    }
            }
            else
            if (MOD[1].size()>=2)
            {
                d[MOD[1][0]]--;
                d[MOD[1][1]]--;
                FOD(i,9,0)
                    while (d[i]) 
                    {
                        cout<<i, d[i]--;
                        flag=true;
                    }
            }
        }
        if (!flag) cout<<"-1";
        cout<<"\n";
        FOR(i,0,2) MOD[i].clear(); 
    }    
}
