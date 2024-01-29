#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 
int n;
vector<string> ans;
void chuyen(int n,char a,char b)
{
    ans.push_back(string(1,a)+b);
    ans.push_back(string(1,a)+b);
}
void HN(int n,char a,char b,char c)
{
    if (n==1) chuyen(1,a,c);
    else
    {
        HN(n-1,a,c,b);
        chuyen(n,a,c);
        HN(n-1,b,a,c);
    }
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("D:/ADVANCED ALGORITHMS/thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    n/=2;
    HN(n,'A','B','C');
    cout<<ans.size()<<"\n";
    for (string s : ans) cout<<s<<"\n";
}
