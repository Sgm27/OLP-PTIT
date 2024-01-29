#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 200005
int n,q,a[maxn];
int tmp_val[maxn];
vector<int> compress;
struct query{
	int type,u,v;
} Q[maxn];
struct node{
	int cnt=0,sum=0,ans=0;
	node operator+(node other)
	{
		node answer;
		answer.ans=ans+other.ans;
		answer.sum=sum+other.sum;
		answer.cnt=cnt+other.cnt;
		return answer;
	}
} t[maxn*4];
node Merge(node l,node r)
{
	node res;
	res.cnt=l.cnt+r.cnt;
	res.sum=l.sum+r.sum;
	res.ans=l.ans+r.ans+r.sum*l.cnt-l.sum*r.cnt;
	return res;
}
int find_pos(int x)
{
	return lower_bound(compress.begin(),compress.end(),x)-compress.begin()+1;
}
void update(int id,int l,int r,int p,node val)
{
	if (r<p || l>p) return;
	if (l==r)
	{
		t[id] = t[id] + val;
		return;
	}	 
	int m=l+r >> 1;
	update(id*2,l,m,p,val);
	update(id*2+1,m+1,r,p,val);
	t[id]=Merge(t[id*2],t[id*2+1]);
}
node get(int id,int l,int r,int u,int v)
{
	if (r<u || l>v) return {0,0,0};
	if (l>=u && r<=v) return t[id];
	int m=l+r >> 1;
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
	FOR(i,1,n) 
	{
		cin>>a[i], tmp_val[i]=a[i];
		compress.push_back(a[i]);
	}
	FOR(i,1,q)
	{
		int type,u,v;
		cin>>type>>u>>v;
		Q[i]={type,u,v};
		if (type==1)
		{
			tmp_val[u] += v;
			compress.push_back(tmp_val[u]);
		}
		else
		{
			compress.push_back(u);
			compress.push_back(v);
		}
	}
	sort(compress.begin(),compress.end());
	compress.resize(unique(compress.begin(),compress.end())-compress.begin());
	int SZ=compress.size();
	FOR(i,1,n)
	{
		int posX=find_pos(a[i]);
		update(1,1,SZ,posX,{1,a[i],0});
	}
	FOR(i,1,q)
	{
		int type=Q[i].type;
		int u=Q[i].u;
		int v=Q[i].v;
		if (type==1)
		{
			int pre_pos=find_pos(a[u]);
			update(1,1,SZ,pre_pos,{-1,-a[u],0});
			a[u] += v;
			int new_pos=find_pos(a[u]);
			update(1,1,SZ,new_pos,{1,a[u],0});
		}
		else
		{
			int posU=find_pos(u);
			int posV=find_pos(v);
			cout<<get(1,1,SZ,posU,posV).ans<<"\n";
		}
	}
}
