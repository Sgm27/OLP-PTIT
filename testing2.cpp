#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
 
int count(ll n) 
{
    int cnt = 0;
    double sqr = sqrt(n);
    for (ll i = 1; i <= sqr; i++) 
    {       
        if (n % i == 0) 
        {
            cnt += 2;
            if (i * i == n) 
            {
                cnt--;
            }
        }
    }
    return cnt;
}
 
int main() 
{
    #ifndef ONLINE_JUDGE
	freopen("thu.inp","r",stdin);
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    ll f[501][501];
    for(int i=0;i<=500;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(i==0 || i==j) f[i][j]=1;
            else f[i][j]=f[i-1][j]+f[i-1][j-1];
        }
    }
    ll n, k;
    while(cin>>n>>k)
    {
         cout<<count( f[n][k]) <<endl;
    }
 
    return 0;
}