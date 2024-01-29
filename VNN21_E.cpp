#include<iostream>
#include<algorithm>
#include<string.h>
#include<cstdio>
#include<vector>
#define int long long
using namespace std;

vector<int> num;
long long n;
long long dp[20][140][140][3];
// dp den chu so i, tong chu so cua x hien tai la a,
// tong chu so cua y hien tai la b
// so nho hien tai la f

bool isPrime(int x)
{
    if (x == 0 || x == 1)
        return false;
    for (int i = 2; i * i <= x; i++)
    if (x % i == 0)
        return false;
    return  true;
}

long long FindDP(int pos, int a, int b, int f)
{
    // cout << pos << ' ' << a << ' ' << b << ' ' << f << '\n';
    if (pos == num.size())
    {
        if (isPrime(a) && isPrime(b) && f == 0)
        {
                // cout << pos << ' ' << a << ' ' << b << ' ' << f << '\n';
                return 1;
        }
        return 0;
    }

    if (dp[pos][a][b][f] != -1)
        return dp[pos][a][b][f];

    long long res = 0;
    int high = 9;
    for (int dgt = 0; dgt <= high; dgt++)
    {
        int nf = f, na = a, nb = b;
        na += dgt;

        for (int i = 0; i <= 2; i++)
        {
            nb = b;
            int dgtN = num[pos] - f + 10 * i;
            if (dgtN >= 0 && dgtN >= dgt && (dgtN - dgt) % 2 == 0)
            {
                nf = i;
                int dgtY = (dgtN - dgt) / 2;
                if (dgtY < 10)
                {
                    nb += dgtY;
                    res += FindDP(pos + 1, na, nb, nf);
                }
            }
        }
    }

    // if (pos == 2 && res != 0)
    //     cout << pos << ' ' << a << ' ' << b << ' ' << f << ' ' << res << '\n';
    // if (pos == 1 && res != 0)
    //    cout << pos << ' ' << a << ' ' << b << ' ' << f << ' ' << res << '\n';
    return dp[pos][a][b][f] = res;
}

long long Solve(long long x)
{
    num.clear();
    while (x > 0)
    {
        num.push_back(x % 10);
        x /= 10;
    }
    // reverse(num.begin(), num.end());

    memset(dp, -1, sizeof(dp));
    long long res = FindDP(0, 0, 0, 0);
    return res;
}

int32_t main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("test.inp" , "r" , stdin);
    // freopen("test.out" , "w" , stdout);

    cin >> n;
    int res = Solve(n);
    cout << res << '\n';
}

