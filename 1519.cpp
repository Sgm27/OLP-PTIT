#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 
void process(string s)
{
    stack<int> st;
    for (int i=s.length()-1;i>=0;i--)
    {
        char c=s[i];
        if (isdigit(c)) st.push(c-'0');
        else
        {
            int x1=st.top(); st.pop();
            int x2=st.top(); st.pop();
            if (c=='+') st.push(x1+x2);
            if (c=='*') st.push(x1*x2);
            if (c=='-') st.push(x1-x2);
            if (c=='/') st.push(x1/x2);
        }
    }
    cout<<st.top()<<"\n";
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
