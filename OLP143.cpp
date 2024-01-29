#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 100005
int n,a[maxn],lz[maxn*4],q;
struct node{
	int d0,d1,d2;
	node()
	{
		d0=d1=d2=0;
	}
} t[maxn*4];
node Merge(node l,node r)
{
	node ans;
	ans.d0=l.d0+r.d0;
	ans.d1=l.d1+r.d1;
	ans.d2=l.d2+r.d2;
	return ans;
}
void Push(int id,int l,int r,int m)
{
	if (lz[id])
	{
		if (lz[id]%3==0) 
		{
			lz[id*2] += lz[id];
			lz[id*2+1] += lz[id];
		}
		else
		if (lz[id]%3==1)
		{
			node ansL,ansR;
			ansL.d0=t[id*2].d2;
			ansL.d1=t[id*2].d0;
			ansL.d2=t[id*2].d1;
			ansR.d0=t[id*2+1].d2;
			ansR.d1=t[id*2+1].d0;
			ansR.d2=t[id*2+1].d1;
			t[id*2]=ansL;
			t[id*2+1]=ansR;
			lz[id*2] += lz[id];
			lz[id*2+1] += lz[id];
		}
		else
		{
			// du 2
			node ansL,ansR;
			ansL.d0=t[id*2].d1;
			ansL.d1=t[id*2].d2;
			ansL.d2=t[id*2].d0;
			ansR.d0=t[id*2+1].d1;
			ansR.d1=t[id*2+1].d2;
			ansR.d2=t[id*2+1].d0;
			t[id*2]=ansL;
			t[id*2+1]=ansR;
			lz[id*2] += lz[id];
			lz[id*2+1] += lz[id];
		}
		lz[id]=0;
	}
}
void build(int id,int l,int r)
{
	if (l==r)
	{
		t[id].d0=1;
		return;
	}
	int m=l+r >> 1;
	build(id*2,l,m);
	build(id*2+1,m+1,r);
	t[id]=Merge(t[id*2],t[id*2+1]);
}
void update(int id,int l,int r,int u,int v)
{
	if (r<u || l>v) return;
	if (l>=u && r<=v)
	{
		node ans;
		ans.d0=t[id].d2;
		ans.d1=t[id].d0;
		ans.d2=t[id].d1;
		t[id]=ans;
		lz[id]++;
		return;
	}
	int m= l+r >> 1;
	Push(id,l,r,m);
	update(id*2,l,m,u,v);
	update(id*2+1,m+1,r,u,v);
	t[id]=Merge(t[id*2],t[id*2+1]);
}
node get(int id,int l,int r,int u,int v)
{
	if (r<u || l>v) return node();
	if (l>=u && r<=v) return t[id];
	int m=l+r >> 1;
	Push(id,l,r,m);
	node L=get(id*2,l,m,u,v);
	node R=get(id*2+1,m+1,r,u,v);
	return Merge(L,R); 
}
signed main()
{
	#ifndef ONLINE_JUDGE
	freopen("thu.inp","r",stdin);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>n>>q;
	build(1,1,n);
	while (q--)
	{
		int type,u,v;
		cin>>type>>u>>v;
		if (type==1)
		{
			node ans=get(1,1,n,u,v);
			cout<<ans.d0<<"\n";
		}
		else
			update(1,1,n,u,v);
	}
}
