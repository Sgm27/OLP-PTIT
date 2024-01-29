#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, a, b) for (int i = a; i >= b; i--)
#define TIME "Time elapsed : " << (double)clock() / 1000 << " s"
#define int long long
#define pii pair<int, int>
const int MOD = 1e9 + 7, INF = 1e18;
#define maxn 200005
int n, a[maxn], q;
vector<int> compress;
struct query
{
	int type, u, v;
} Q[maxn];
struct node
{
	int Lpoint, Rpoint, answer, cnt;
	// Lpoint is the point in the left of node id(lowest point)
	// Rpoint is the point in the right of node id(highest point)
	node()
	{
		Lpoint = INF;
		Rpoint = -INF;
		answer = INF;
		cnt = 0;
	}
};
vector<node> t;
node Merge(node l, node r)
{
	node ans;
	if (!l.cnt)
		return r;
	if (!r.cnt)
		return l;
	ans.answer = min({l.answer, r.answer, abs(r.Lpoint - l.Rpoint)});
	ans.Lpoint = l.Lpoint;
	ans.Rpoint = r.Rpoint;
	ans.cnt = l.cnt + r.cnt;
	return ans;
}
int find_pos(int x)
{
	return lower_bound(compress.begin(), compress.end(), x) - compress.begin() + 1;
}
void update(int id, int l, int r, int p, int val)
{
	if (r < p || l > p)
		return;
	if (l == r)
	{
		t[id].Lpoint = min(t[id].Lpoint, val);
		t[id].Rpoint = max(t[id].Rpoint, val);
		t[id].cnt++;
		if (t[id].cnt <= 1)
			t[id].answer = INF;
		else
			t[id].answer = 0;
		return;
	}
	int m = l + r >> 1;
	update(id * 2, l, m, p, val);
	update(id * 2 + 1, m + 1, r, p, val);
	t[id] = Merge(t[id * 2], t[id * 2 + 1]);
}
node get(int id, int l, int r, int u, int v)
{
	if (r < u || l > v)
		return node();
	if (l >= u && r <= v)
		return t[id];
	int m = l + r >> 1;
	node L = get(id * 2, l, m, u, v);
	node R = get(id * 2 + 1, m + 1, r, u, v);
	return Merge(L, R);
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("thu.inp", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n >> q;
	FOR(i, 1, n)
	{
		cin >> a[i];
		compress.push_back(a[i]);
	}
	FOR(i, 1, q)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			int p;
			cin >> p;
			compress.push_back(p);
			Q[i].type = 1, Q[i].u = p;
		}
		else
		{
			int u, v;
			cin >> u >> v;
			compress.push_back(u);
			compress.push_back(v);
			Q[i] = {type, u, v};
		}
	}
	sort(compress.begin(), compress.end());
	compress.resize(unique(compress.begin(), compress.end()) - compress.begin());
	int SZ = compress.size();
	t.resize(SZ * 4);
	FOR(i, 1, n)
	{
		int PosX = find_pos(a[i]);
		update(1, 1, SZ, PosX, a[i]);
	}
	FOR(i, 1, q)
	{
		int type = Q[i].type;
		int u = Q[i].u;
		if (type == 1)
		{
			int PosU = find_pos(u);
			update(1, 1, SZ, PosU, u);
		}
		else
		{
			int v = Q[i].v;
			int PosU = find_pos(u);
			int PosV = find_pos(v);
			node result = get(1, 1, SZ, PosU, PosV);
			if (result.cnt <= 1)
				cout << "-1\n";
			else
				cout << result.answer << "\n";
		}
	}
}
