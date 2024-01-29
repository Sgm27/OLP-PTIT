#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 

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
        stack<int> st;
        for (int i=0;i<s.length();i++)
        {
            if (s[i]=='(') st.push(i);
            else
            {
                if (!st.empty() && s[st.top()]=='(') st.pop();
                else st.push(i);
            }
        }   
        int op=0;
        int cl=0;
        while (!st.empty())
        {
            int c=st.top();
            st.pop();
            if (s[c]=='(') op++; else cl++;
        }	
        if (op%2) cout<<(op+1)/2+(cl+1)/2;
        else cout<<(op+cl)/2;
        cout<<"\n";
    }
}
