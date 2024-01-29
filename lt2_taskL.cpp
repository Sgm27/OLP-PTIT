#include<iostream>
#include<cstdio>
using namespace std;

const int maxN = 5e5 + 5;
struct TSegmentTree
{
    int L[4 * maxN], H[4 * maxN];
    long long sum[4 * maxN], Lazy[4 * maxN];
    int leaf[maxN];

    void Build(int x, int low, int high)
    {
        L[x] = low; H[x] = high;
        if (low == high)
        {
            sum[x] = 0;
            Lazy[x] = 0;
            leaf[low] = x;
        }
        else
        {
            int mid = (low + high) / 2;
            Build(2 * x, low, mid); Build(2 * x + 1, mid + 1, high);
            sum[x] = sum[2 * x] + sum[2 * x + 1];
            Lazy[x] = 0;
        }
    }

    void Down(int x)
    {
        Lazy[x * 2] += (long long) Lazy[x];
        sum[x * 2] += (long long)(H[x*2]-L[x*2]+1)*Lazy[x];

        Lazy[x * 2 + 1] += (long long) Lazy[x];
        sum[x * 2 + 1] += (long long)(H[x*2+1]-L[x*2+1]+1)*Lazy[x];

        Lazy[x] = 0;
    }

    void Update(int x, int l, int r, int w)
    {
        if (r < L[x] || l > H[x])
            return;

        if (l <= L[x] && H[x] <= r)
        {
            sum[x] += (long long) w * ((long long) H[x] - L[x] + 1);
            Lazy[x] += (long long) w;
            return;
        }

        Down(x);
        Update(2 * x, l, r, w); Update(2 * x + 1, l, r, w);
        sum[x] = sum[2 * x] + sum[2 * x + 1];
    }

    int qi, qj;
    long long Request(int x)
    {
        if (H[x] < qi || L[x] > qj)
            return 0;

        if (qi <= L[x] && H[x] <= qj)
            return sum[x];

        Down(x);
        return Request(2 * x) + Request(2 * x + 1);
    }

    long long Query(int l, int r)
    {
        qi = l; qj = r;
        return Request(1);
    }
} ST;
int n, m, a[maxN], pos[maxN], pre[maxN];

void input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
        pre[a[i]] = 0;
    }
}

void solve()
{
    ST.Build(1, 1, n);

    long long res = 0;

    for (int i = 1; i <= m; i++)
    {
        int x; char c;
        cin >> x >> c;

        int currentPosition = pos[x] + ST.Query(pos[x], pos[x]) - pre[x];
        // cout << x << ' ' << pos[x] << ' ' << ST.Query(pos[x], pos[x]) << ' ' << pre[x] << '\n';
        cout << currentPosition << ' ' << min(currentPosition - 1, n - currentPosition) << '\n';
        res += (long long) min(currentPosition - 1, n - currentPosition);
        if (c == 'l')
        {
            pos[x] = 1;
            ST.Update(1, 1, currentPosition - 1, 1);
            pre[x] = ST.Query(1, 1);
        }
        else
        {
            pos[x] = n;
            ST.Update(1, currentPosition + 1, n, -1);
            pre[x] = ST.Query(n, n);
        }

        // for (int i = 1; i <= n; i++)
        // {
        //    cout << ST.Query(i, i) << '\n';
        // }
    }

    cout << res;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    freopen("thu.out","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    

    input();
    solve();
}

