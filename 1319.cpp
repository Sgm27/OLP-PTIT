#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 
string s;
int k;
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
        cin>>k>>s;
        int idx=0;
        while (k && (idx<s.size()-1))
        {
            int pos=-1;
            char Max='0';
            for (int i=idx+1;i<s.size();i++) 
                if (s[i]>=Max) 
                {
                    Max=s[i];
                    pos=i;
                }
            if (pos!=-1 && s[pos]>s[idx])
            {
                swap(s[pos],s[idx]);
                k--;
            }
            idx++;
        }
        cout<<s<<"\n";
    }
}
