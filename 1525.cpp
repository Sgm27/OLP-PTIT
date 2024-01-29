#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 
vector<string> v;
bool bigmod(string s,int n)
{
	int res=0;
	for (char k : s)
	{
		res=(res*10+(k-'0'))%n;
	}
	return res==0;
}
void init()
{
    queue<string> Q;
    Q.push("1");
    v.push_back("1");
    while (1)
    {
        string s=Q.front();
        Q.pop();
        string t1=s+'0',t2=s+'1';
        if (t1.length()==20) break;
        Q.push(t1); Q.push(t2);
        v.push_back(t1);
        v.push_back(t2);
    }
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    init();
    int tc; cin>>tc;
    while (tc--)
    {
        int n; cin>>n;	
        for (string s : v)
            if (bigmod(s,n)) 
            {
                cout<<s<<"\n";
                break;
            }
    }
}
