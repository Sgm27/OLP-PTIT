#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, a, b) for (int i = a; i >= b; i--)
#define TIME "Time elapsed : " << (double)clock() / 1000 << " s"
#define int long long
#define pii pair<int, int>
const int MOD = 1e9 + 7, INF = 9e18;
#define maxn 105
int n, a[maxn][maxn], sum[maxn][maxn];
void calc_prefix()
{
    FOR(i, 1, n)
    FOR(j, 1, n)
    {
        sum[i][j] = a[i][j];
        sum[i][j] += sum[i - 1][j];
        sum[i][j] += sum[i][j - 1];
        sum[i][j] -= sum[i - 1][j - 1];
    }
}
void process()
{
    bool flag = true;
    calc_prefix();
    FOR(len, 2, n)
    FOR(i, 1, n - len + 1)
    FOR(j, 1, n - len + 1)
    {
        int sub_sum = 0;
        sub_sum = sum[i + len - 1][j + len - 1];
        sub_sum -= sum[i - 1][j + len - 1];
        sub_sum -= sum[i + len - 1][j - 1];
        sub_sum += sum[i - 1][j - 1];
        if (sub_sum % 2 == 0)
        {
            return cout << "NO\n", void();
        }
    }
    cout << "YES\n";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--)
    {
        cin >> n;
        FOR(i, 1, n)
        FOR(j, 1, n)
        cin >> a[i][j];
        process();
    }
}
