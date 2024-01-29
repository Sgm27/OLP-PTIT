#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define maxn 205
int k;
string f[maxn][105];
string s;
string cong(string a,string b)
{
	string res="";
	while (a.length()<b.length()) a="0"+a;
	while (b.length()<a.length()) b="0"+b;
	int nho=0;
	for (int i=a.length()-1;i>=0;i--)
	{
		int tmp=(a[i]-'0')+(b[i]-'0')+nho;
		if (tmp>=10) nho=1;
		else nho=0;
		tmp%=10;
		res=(char)(tmp+'0')+res;
	}
	if (nho) res="1"+res;
	return res;
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
        s.clear();
        int n;
        cin >>n;
        s.push_back(' ');
        FOR(i,1,n) s.push_back('?');

        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                f[i][j] = f[i][j] = "0";
        f[0][0] = "1";
        for (int i = 0; i < n; i++)
        {
            for (int bac = 0; bac <= n/2; bac++)
            {
                if (f[i][bac] != "0")
                {
                    if (s[i + 1] == '?')
                    {
                        f[i + 1][bac + 1]= cong(f[i + 1][bac + 1], f[i][bac]);
                        if (bac - 1 >= 0)
                            f[i + 1][bac - 1] = cong(f[i][bac], f[i + 1][bac - 1]);
                    }
                }
            }
        }
        string ans=f[n][0];
        if (ans.size()>10) 
        {
            FOR(i,0,4) cout<<ans[i];
            cout<<"...";
            FOR(i,ans.length()-5,ans.length()-1) cout<<ans[i];
        }
        else cout<<ans;
        cout<<"\n";
    }
}
