#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,k;
void process()
{
	if ((k-1)%2==0) 
	{
		cout<<"1\n";
		return;
	}
	ll cs1=1,cs2;
	for (int i=2;i<=n;i++)
	{
		cs1*=2;
		cs2=cs1*2;
		if ((k-cs1)%cs2==0) 
		{
			cout<<i<<endl;
			return;
		}
	}
}
int main()
{
	// freopen("thu.inp","r",stdin);
	int tc;
	cin>>tc;
	while (tc--)
	{
		cin>>n>>k;
		process();
	}
}
