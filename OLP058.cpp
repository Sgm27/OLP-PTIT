#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 2000006 
string s;
int z[maxn],n,m;
void calc_Z()
{
    n=s.length();
    s=" "+s;    
    z[1]=0;
    int l,r=0;
    for (int i=2;i<=n;i++)
    {
        int x=0;
        if (i<=r) x=min(z[i-l+1],r-i+1);
        while (i+x<=n && s[x+1]==s[i+x]) x++;
        z[i]=x;
        if (r < i+x-1)
        {
            r=i+x-1;
            l=i;
        }
    }
    for (int i=m+1;i<=n;i++)
        if (z[i]==m) cout<<i-m-1<<" ";
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    string tmp1,tmp2;
    cin>>tmp1>>tmp2;
    m=tmp2.length();
    s=tmp2+"*"+tmp1;
    calc_Z();
}
