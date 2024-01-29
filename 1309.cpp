#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 

signed main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        string s;
        cin>>s;
        int pos=-1;
        FOD(i,s.length()-1,0)
            if (s[i]=='0') 
            {
                pos=i;
                break;
            }
        if (pos==-1)
            FOR(i,1,s.length()) cout<<0;
        else
        {
            s[pos]='1';
            FOR(i,pos+1,s.length()-1) s[i]='0';
            cout<<s;
        }
        cout<<"\n";
    }    
}
