#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define pii pair<int,int>
using ll = long long;
#define maxn 50004
string s;
int d[maxn*2];
void manacher(string t)
{
	s=".";
	for(char x : t) s+=x, s+=".";
	int n=s.length();
	int l=0,r=-1,ans=0;
	FOR(i,0,n-1)
	{
		int k=0;
		if (i<=r) k=min(r-i,d[r-i+l]);
		while (i+k+1<n && i-k-1>=0 && s[i+k+1]==s[i-k-1]) k++;
		d[i]=k;
		if (i+k>r) l=i-k, r=i+k;
		ans=max(ans,d[i]);
	}
	// .B.A.B.B.A.A.B.
	// FOR(i,0,n-1) cout<<d[i]<<" "; cout<<"\n";
    for (int i=1;i<n;i+=2) cout<<max(d[i],d[i+1])<<" "; cout<<"\n";
	cout<<ans;
}
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int x; cin>>x;
	string t; cin>>t;
	manacher(t);
}
