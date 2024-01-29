struct DSU{
	vector<int> r;
	int n;
	DSU(int sz)
	{
		n=sz;
		r.resize(sz+1);
		FOR(i,1,n) r[i]=i;
	}
	int get_root(int u)
	{
		if (u==r[u]) return u;
		return r[u]=get_root(r[u]);
	}
	bool join(int u,int v)
	{
		u=get_root(u);
		v=get_root(v);
		if (u==v) return 0;
		return r[u]=v, 1;
	}
};