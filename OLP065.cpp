#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 5;
const long long MOD = 1e9 + 7;

long long IT[4 * N], lazy2[4 * N], pwr[N], sum[N];
pair<long long, long long> lazy[4 * N];

// Formula
/// For query 1 x y, with x <= i <= y
/// a[i] increased by: (i-x+1)*(i-x+2) = (i^2 + 3*i + 2) + (x^2 - 2*x*i - 3*x)
/// Sum of [l, r] with x <= l <= r <= y increased by:
/// ((l^2 + (l+1)^2 + ... + r^2) + 3*(l + l+1 + ... + r) + 2*(r-l+1)) + (x^2*(r-l+1) - 2*(l + l+1 + l+2 +... + r)*x - 3*x*(r-l+1))
/// -> after cnt queries on [l, r], sum of [l, r] is increased by:
/// ((l^2 + (l+1)^2 + ... + r^2) + 3*(l + l+1 + ... + r) + 2*(r-l+1)) * cnt + ((x1^2 + x2^2 + ...)*(r-l+1) - 2*(l + l+1 + l+2 +... + r)*(x1 + x2 + ...) - 3*(x1 + x2 + x3+ ...)*(r-l+1))

/// @brief
/// lazy[].first: cnt
/// lazy[].second: sum of x
/// lazy2[]: sum of x^2
void Push(int id, int l, int r)
{
    if (!lazy[id].first)
        return;

    if (l == r)
    {
        // cout << lazy[id].first << ' ' << lazy[id].second << ' ' << lazy2[id] << endl;
        IT[id] = (IT[id] + ((l * l + 3 * l + 2) * lazy[id].first % MOD) + (-2 * l * lazy[id].second % MOD) + (-3 * lazy[id].second % MOD) + lazy2[id] + MOD * MOD) % MOD;
        lazy[id].first = lazy[id].second = 0;
        lazy2[id] = 0;
        return;
    }

    lazy[id * 2].first = lazy[id * 2].first + lazy[id].first;
    lazy[id * 2 + 1].first = lazy[id * 2 + 1].first + lazy[id].first;

    lazy[id * 2].second = (lazy[id * 2].second + lazy[id].second) % MOD;
    lazy[id * 2 + 1].second = (lazy[id * 2 + 1].second + lazy[id].second) % MOD;

    lazy2[id * 2] = (lazy2[id * 2] + lazy2[id]) % MOD;
    lazy2[id * 2 + 1] = (lazy2[id * 2 + 1] + lazy2[id]) % MOD;

    IT[id] = (IT[id] + (((pwr[r] - pwr[l - 1]) + 3 * (sum[r] - sum[l - 1]) + 2 * (r - l + 1)) * lazy[id].first % MOD) + (-2 * (sum[r] - sum[l - 1]) * lazy[id].second % MOD) + (-3 * (r - l + 1) * lazy[id].second % MOD) + (lazy2[id] * (r - l + 1) % MOD) + MOD * MOD) % MOD;
    lazy[id].first = lazy[id].second = 0;
    lazy2[id] = 0;
    return;
}

void Update(int id, int l, int r, int u, int v)
{
    Push(id, l, r);
    if (v < l || r < u)
        return;

    if (u <= l && r <= v)
    {
        lazy[id].first++;
        lazy[id].second += u;
        lazy[id].second %= MOD;
        lazy2[id] = (lazy2[id] + 1LL * u * u) % MOD;
        Push(id, l, r);
        return;
    }

    int mid = (l + r) >> 1;
    Update(id * 2, l, mid, u, v);
    Update(id * 2 + 1, mid + 1, r, u, v);
    IT[id] = (IT[id * 2] + IT[id * 2 + 1]) % MOD;
    return;
}

int Get(int id, int l, int r, int u, int v)
{
    Push(id, l, r);
    if (v < l || r < u)
        return 0;

    if (u <= l && r <= v)
        return IT[id];

    int mid = (l + r) >> 1;
    return (Get(id * 2, l, mid, u, v) + Get(id * 2 + 1, mid + 1, r, u, v)) % MOD;
}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    int m, n;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        sum[i] = (sum[i - 1] + i) % MOD;
        pwr[i] = (pwr[i - 1] + 1LL * i * i) % MOD;
    }

    while (m--)
    {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1)
            Update(1, 1, n, x, y);
        else
        {
            // for (int i = 1; i <= n; i++)
            //     cout << Get(1, 1, n, i, i) << ' ';
            // cout << endl;
            cout << Get(1, 1, n, x, y) << endl;
        }
    }
    return 0;
}