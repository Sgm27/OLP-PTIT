#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 
string s;
int pre(char x)
{
    if (x=='(') return 0;
    if (x=='+' || x=='-') return 1;
    if (x=='*' || x=='/') return 2;
    if (x=='^') return 3;
}
void process(string s)
{
    string ans="";
    stack<char> st;
    for (char c : s)
    {
        if (isalpha(c)) ans+=c;
        else
        {
            if (c=='(') st.push(c);
            else
            if (c==')')
            {
                while (!st.empty() && st.top()!='(') 
                {
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while (!st.empty() && pre(st.top())>=pre(c))
                {
                    ans+=st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
    }
    while (!st.empty())
    {
        ans+=st.top();
        st.pop();
    }
    cout<<ans<<"\n";
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
