#include<bits/stdc++.h>
using namespace std;
typedef pair <int, int> ii;
#define fi                 first
#define se             second
#define pb             push_back
#define int long long
int t, n;
int f[1000006][2];
int sang[1000006];
int mod;
int Cong(int a, int b)
{
    int x = a + b;
    if (x >= mod)
        return x % mod;
    while (x < 0)
        x += mod;
    return x;
}
int mu(int a, int k)
{
    if (k == 0)
        return 1;
    int x = mu(a, k >> 1);
    x = (x * x) % mod;
    if (k % 2)
        x = (x * a) % mod;
    return x % mod;
}
void s()
{
    sang[0] = 1;
    sang[0] = 1;
    for (int i = 2; i * i <= 1000000; i++)
        if (sang[i] == 0)
            for (int j = i * i; j <= 1000000; j += i)
                sang[j] = i;
    for (int i = 1; i <= 1000000; i++)
        if (sang[i] == 0)
            sang[i] = i;
}
unordered_map<int, int>p;
struct query
{
    int n, m, i;
};
vector<query>q;
int ans[100005];
bool cmp(query a, query b)
{
    return a.n < b.n;
}
signed main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("thu.inp", "r", stdin);
    //freopen("thu.out", "w", stdout);
    cin >> t;
    s();
    for (int i = 1; i <= t; i++)
    {
        cin >> n >> mod;
        q.push_back({n, mod, i});
    }
    sort(q.begin(), q.end(), cmp);
    int r = 1;
    for (int i = 0; i < q.size(); i++)
    {
        int n = q[i].n;
        mod=q[i].m;
        f[1][1] = 1;
        f[1][0] = 1;
        for (int i = 2; i <= n; i++)
        {
            f[i][0] = Cong(f[i - 1][1], f[i - 1][0]);
            f[i][1] = f[i - 1][0];
        }
        if (n % 2 == 1)
        {
            ans[q[i].i] = Cong(f[n][0], f[n][1]);
            continue;
        }
        for (int i = r+1; i <= n; i++)
        {
            int x = i;
            while (x != 1)
            {
                int k = sang[x];
                p[k]++;
                x /= k;
            }
        }
        for (int i = r / 2+1; i <= n / 2; i++)
        {
            int x = i;
            while (x != 1)
            {
                int k = sang[x];
                p[k] -= 2;
                x /= k;
            }
        }
        r = n;
        int res = 1;
        for (auto x : p) 
            res = (res * mu(x.fi, x.se)) % mod;
        //cout<<n<<" "<<res<<'\n';
        ans[q[i].i] = Cong(Cong(f[n][1], f[n][0]), Cong(res, -(n / 2 + 1)));
    }
    for (int i = 1; i <= t; i++)
        cout << ans[i] << '\n';
    return 0;

}