#include<bits/stdc++.h>
using namespace std;
#define fi                 first
#define se             second
#define pb             push_back
#define int long long
typedef pair <int, int> ii;
int n;
int a[300005];
int f[300005];
int g[300005];
int mark[300005];
vector<ii>v;
ii st[300005 * 4];
void update(int id, int l, int r, int i, int val)
{
    if (i < l || i > r)
        return;
    if (l == r)
    {
        st[id] = {val, 1};
        return;
    }
    int mid = (l + r) >> 1;
    update(id * 2, l, mid, i, val);
    update(id * 2 + 1, mid + 1, r, i, val);
    st[id].fi = st[id * 2].fi + st[id * 2 + 1].fi;
    st[id].se = st[id * 2].se + st[id * 2 + 1].se;
}
int get(int id, int l, int r, int k)
{
    int mid = (l + r) >> 1;
    if (l == r)
        return st[id].fi;
    if (st[id * 2].se < k)
        return get(id * 2 + 1, mid + 1, r, k - st[id * 2].se) + st[id * 2].fi;
    if (st[id * 2].se > k)
        return get(id * 2, l, mid, k);
    if (st[id * 2].se == k)
        return st[id * 2].fi;
}
signed main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n * 3; i++)
        cin >> a[i], v.push_back({a[i], i});
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        mark[v[i].se] = i + 1;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        update(1, 1, 3 * n, mark[i], a[i]);
        sum += a[i];
    }
    f[n] = sum;
    for (int i = n + 1; i <= 2 * n; i++)
    {
        sum += a[i];
        update(1, 1, 3 * n, mark[i], a[i]);
        f[i] = sum - get(1, 1, 3 * n, i - n);
    }


    sort(v.begin(), v.end(), greater<ii>());
    for (int i = 0; i < v.size(); i++)
        mark[v[i].se] = i + 1;
    sum = 0;
    for (int i = 1; i <= 3 * n * 4; i++)
        st[i] = {0, 0};
    for (int i = 3 * n; i >= 2 * n+1; i--)
    {
        sum += a[i];
        update(1, 1, 3 * n, mark[i], a[i]);
    }
    g[2 * n + 1] = sum;
    for (int i = 2 * n; i >= n + 1; i--)
    {
        sum += a[i];
        update(1, 1, 3 * n, mark[i], a[i]);
        g[i] = sum - get(1, 1, 3 * n, 2*n-i+1);
        //cout<<sum<<" "<<g[i]<<"\n";
    }
    int ans = -1e18;
    for (int i = n; i <= 2 * n; i++)
        ans = max(ans, f[i] - g[i + 1]);
    cout << ans;



    return 0;

}