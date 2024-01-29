#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 
struct bracket{
    int fre,idx;
};
void process(string s)
{
    stack<bracket> st;
    int t=0,i=0;
    string ans="";
    while (i<s.length())
    {
        if (isalpha(s[i])) ans+=s[i];
        while (isdigit(s[i])) t=t*10+(s[i]-'0'), i++;
        if (s[i]=='[') st.push({t,ans.size()}), t=0;
        if (s[i]==']') 
        {
            bracket x=st.top();
            st.pop();
            string tmp=ans.substr(x.idx,ans.size()-x.idx);
            FOR(k,1,x.fre-1) ans+=tmp;
        }
        i++;
    }
    cout<<ans<<'\n';
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
        string s;
        cin>>s;
        process(s);	
    }
}
