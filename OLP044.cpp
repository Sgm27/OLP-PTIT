#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 

bool open(char x)
{
    if (x=='{' || x=='[' || x=='(') return 1;
    return 0;
}
bool process(string s)
{
    stack<int> st;
    for (int i=0;i<s.length();i++)
        if (open(s[i])) st.push(i);
        else   
        {
            if (st.empty()) return 0;
            if (s[i]=='}' && s[st.top()]=='{') st.pop();
            else
            if (s[i]==')' && s[st.top()]=='(') st.pop();
            else 
            if (s[i]==']' && s[st.top()]=='[') st.pop();
            else return 0;
        }
    return 1;
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
        string s; cin>>s;
        cout<<(process(s) ? "YES\n" : "NO\n");
    }
}
