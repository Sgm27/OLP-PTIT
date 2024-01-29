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
        int pos=-1;
        FOR(i,0,s.length()-1)
            if (s[i]=='1') pos=i;
        if (pos==-1) 
            for (char x : s) cout<<"1";
        else
        {
            s[pos]='0';
            FOR(i,pos+1,s.length()-1) s[i]='1';
            cout<<s;
        }
        cout<<"\n";
    }    
}
