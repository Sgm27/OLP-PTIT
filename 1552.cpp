#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" ms"
#define int long long
#define pii pair<int,int>
#define maxn 505
#define limit 500*500
int n,b[maxn*maxn],fw[maxn][maxn];
struct data{
    int val,x,y;
} a[maxn*maxn];
void update(int x,int y)
{
    for (int i=x;i<=n;i+=i&-i)
        for (int j=y;j<=n;j+=j&-j) fw[i][j]++;
}
int get(int x,int y)
{
    int ans=0;
    for (int i=x;i>0;i-=i&-i)
        for (int j=y;j>0;j-=j&-j) ans+=fw[i][j];
    return ans;
}
bool cmp(data a,data b)
{
    return a.val<b.val;
}
void process()
{
    memset(fw,0,sizeof(fw));
    int res=0;
    stack<data> st;
    st.push({0,0,0});
    sort(a+1,a+1+n*n,cmp);
    FOD(i,n*n,1)
    {
        if (a[i].val==st.top().val) st.push(a[i]);
        else 
        {
            while (st.size()>1) 
            {
                update(st.top().x,st.top().y);
                st.pop();
            }
            st.push(a[i]);
        }
        res+=get(a[i].x,a[i].y);
    }
    cout<<res<<"\n";
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
        cin>>n;
        int ans=0,idx=0;
        FOR(i,1,n)
            FOR(j,1,n) 
            {
                cin>>a[++idx].val, b[idx]=a[idx].val;
                a[idx].x=i, a[idx].y=j;
            }	
        process();
    }
    cerr<<TIME;
}
