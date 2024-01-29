//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x,y) if (x > y) x = y
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "thu"
#define maxn 45002
#define maxm 5000002
#define MAX 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

struct edge{
    int u, v, c, f;
    edge(int _u = 0, int _v=0, int _c=0, int _f=0): u(_u), v(_v), c(_c), f(_f){};
};

int  n, m, s, t;
int tr[maxn];
long long maxflow = 0;
int tt = 0;
edge e[maxm*2];
vector <int> ke[maxn];
int qu[maxn];


void read()
{
    cin >> n >> m >> s >> t;
    int u, v, cnt = 0, cap;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> cap;
        ke[u].PB(cnt);
        e[cnt++] = edge(u, v, cap, 0);
        ke[v].PB(cnt);
        e[cnt++] = edge(v, u, 0, 0);
    }
}

bool Find_path()
{
    memset(tr, 0, sizeof(tr));
    tr[s] = -1;// khac 0
    int l = 1, r = 1;
    qu[1] = s;
    while (l <= r)
    {
        int u = qu[l++];
        for (int i = 0; i < ke[u].size(); i++)
        {
            int id = ke[u][i];
            int v = e[id].v;
            if (!tr[v] && e[id].c > e[id].f)
            {
                tr[v] = id, qu[++r] = v;
                if (v == t) return true;
            }
        }
    }
    return false;
}

void IncFlow()
{
    int delta = MAX;
    int v = t;
    while (v != s)
    {
        int id = tr[v];
        delta = min(delta, e[id].c - e[id].f) ;
        v = e[id].u;
    }
    v = t;
    while (v != s)
    {
        int id = tr[v];
        e[id].f += delta;
        e[id^1].f -= delta;
        v = e[id].u;
    }
    maxflow += delta;
}

int main()
{
	ios_base::sync_with_stdio(0);
    // freopen(Task".inp", "r", stdin);
    // freopen(Task".out", "w", stdout);
    read();
    clock_t _start = clock();
    while (Find_path())
        IncFlow();
    cout << maxflow ; 
    return 0;
}
