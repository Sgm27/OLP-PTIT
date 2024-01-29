#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 100005
string s;
int ps[maxn],n,ans;
bool match(int x,int y)
{
    if ((s[x]=='[' && s[y]==']') || (s[x]=='(' && s[y]==')')) return true;
    return false;
}
void process()
{
    stack<int> st;
    st.push(0);
    FOR(i,1,n)
    {
        if (s[i]=='[' || s[i]=='(') st.push(i);
        else
        {
            int t=st.top();
            st.pop();
            if (st.size() && match(t,i)) ans=max(ans,ps[i]-ps[st.top()]);
            else 
            {
                while (st.size()) st.pop();
                st.push(i);
            }
        }
    }
    cout<<ans;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>s;
    n=s.length();
    s=" "+s;
    FOR(i,1,n) ps[i]=ps[i-1]+(s[i]=='[');
    process();
}
