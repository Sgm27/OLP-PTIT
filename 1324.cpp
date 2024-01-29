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
	freopen("thu.out","w",stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int tc; cin>>tc;
	while (tc--)
	{
		int tu,mau;
		cin>>tu>>mau;
		int ans;
		while (1)
		{
			if (mau%tu==0)
			{
				cout<<"1/"<<mau/tu<<"\n";
				break;
			}
			else
			{
				ans= mau/tu+1;
				cout<<"1/"<<ans<<" + ";
				tu=tu*ans-mau;
				mau*=ans;
			}
		}
	}	
}
