#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 
string convert(string s)
{
    string ans="";
    int n=s.length(),flip=0;
    s="#"+s;
    stack<int> st;
    for (int i=1;i<=n;i++) 
    {
        if (s[i]=='(' && s[i-1]=='-')
        {
            st.push(i);
            flip^=1;
        }
        else 
        if (s[i]==')' && st.size()) flip^=1, st.pop(); 
        if (isalpha(s[i])) ans+=s[i];
        else 
        {
            if (s[i]=='(' || s[i]==')') continue;
            if (s[i]=='+' && flip) ans+='-';
            else
            if (s[i]=='-' && flip) ans+='+';
            else ans+=s[i];
        }
    }
    return ans;
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
        string s,t;
        cin>>s>>t;
        if (convert(s)==convert(t)) cout<<"YES\n"; else cout<<"NO\n";	
    }
}
