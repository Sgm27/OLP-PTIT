#include<bits/stdc++.h>
using namespace std;
typedef pair <int, int> ii;
#define fi                 first
#define se             second
#define pb             push_back
#define int long long
int n, q;
int a[1000005];
ii Limit[1000005];
struct it
{
    int sum;
    int mi;
};
it st[2 * 4000005];
void update(int id, int l, int r, int i, it val)
{
    if (i > r || i < l)
        return;
    if (l == r)
    {
        st[id] = val;
        return;
    }
    int mid = (l + r) >> 1;
    update(id * 2, l, mid, i, val);
    update(id * 2 + 1, mid + 1, r, i, val);
    if (a[st[id * 2].mi] <= a[st[id * 2 + 1].mi])
        st[id].mi = st[id * 2].mi;
    else
        st[id].mi = st[id * 2 + 1].mi;
    st[id].sum = st[id * 2].sum + st[id * 2 + 1].sum;
}
int getsum(int id, int l, int r, int u, int v)
{
    if (r < u || l > v)
        return 0;
    if (u <= l && r <= v)
        return st[id].sum;
    int mid = (l + r) >> 1;
    return getsum(id * 2, l, mid, u, v) + getsum(id * 2 + 1, mid + 1, r, u, v);
}
int getmin(int id, int l, int r, int u, int v)
{
    if (r < u || l > v)
        return 0;
    if (u <= l && r <= v)
        return st[id].mi;
    int mid = (l + r) >> 1;
    int x = getmin(id * 2, l, mid, u, v);
    int y = getmin(id * 2 + 1, mid + 1, r, u, v);
    if (a[x] <= a[y])
        return x;
    return y;
}
signed main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    cin >> n >> q;
    a[0] = 1e9;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        update(1, 1, 2 * n, i, {a[i], i});
    for (int i = n + 1; i <= 2 * n; i++)
        update(1, 1, 2 * n, i, {a[i - n], i - n});
    for (int i = 1; i <= n; i++)
        Limit[i].fi = n+1-(i-1), Limit[i].se = 2*n-(i-1);
    int tt = 1;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int d;
            cin >> d;
            d %= n;
            tt += d;
            if (tt > n)
                tt -= n;
        }


        if (type == 2)
        {
            int s, t, p;
            cin >> s >> t >> p;
            // cout<<Limit[tt].fi+s-1<<" "<<Limit[tt].fi+t-1<<'\n';
            int vt = getmin(1, 1, 2 * n, Limit[tt].fi + s - 1, Limit[tt].fi + t - 1);
           // cout<<vt<<"\n";

            if (vt > n)
            {
                a[vt - n] = p;
                update(1, 1, 2 * n, vt, {p, vt - n});
                update(1, 1, 2 * n, vt - n, {p, vt - n});
            }
            else
            {
                a[vt] = p;
                update(1, 1, 2 * n, vt, {p, vt});
                update(1, 1, 2 * n, vt + n, {p, vt});
            }
        }
        if (type == 3)
        {
            int s, t;
            cin >> s >> t;
            cout << getsum(1, 1, 2 * n, Limit[tt].fi + s - 1, Limit[tt].fi + t - 1) << '\n';
        }

    }

    return 0;

}

