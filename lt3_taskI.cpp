#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair <int, int> ii;
#define fi                 first
#define se             second
#define pb             push_back
string s;
int Next[1000006][10];
int t;
int bac[1000006];
string ans1;
int F(int n)
{ 
    if (n >= s.size())
        return 0;
    if (bac[n] != -1)
        return bac[n];
    int res = 1e9;
    for (int i = 0; i <= 9; i++)
    {
        int t = Next[n][i];
        // cout<<n<<" "<<i<<" "<<t<<'\n';
        res = min(res, F(t) + 1);
    }
    return bac[n] = res;
}
void getans(int n)
{
    if (n > s.size())
        return;
    for (int i = 0; i <= 9; i++)
    {
        int t = Next[n][i];
        // cout<<n<<" "<<i<<" "<<t<<'\n';
        if (bac[n] == F(t) + 1)
        {
            ans1.push_back(i + '0');
            getans(t);
            return;
        }
    }
}
signed main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen(".out", "w", stdout);
    cin >> t;
    while (t--)
    {
        cin >> s;
        s = ' ' + s;
        memset(Next, 0, sizeof(Next));
        for (int cs = 0; cs <= 9; cs++)
        {
            int r = 1;
            for (int i = 1; i < s.size(); i++)
            {
                if (r == i)
                    r++;
                while (r < s.size() && (s[r] - '0') != cs)
                    r++;
                Next[i][cs] = r;
            }
        }
       
         ii ans = {1e9, 1e9};
        for (int i = 1; i < s.size(); i++)
            bac[i] = -1;
        int kt1 = 0;
        for (int cs = 1; cs <= 9; cs++)
        {
            int kt = 0;
            for (int i = 1; i < s.size(); i++)
            {
                if ((s[i] - '0') == cs)
                {
                    kt = 1;
                    if (ans.fi>F(i))
                    {
                        ans.fi=F(i);
                        ans.se=i;

                    }
                    break;
                }
            }
            if (kt == 0)
            {
                kt1 = 1;
                cout << cs << '\n';
                break;
            }
        }
        if (kt1)
            continue;
        ans1.clear();
        ans1.push_back(s[ans.se]);
        getans(ans.se);
        cout<<ans1<<'\n';

    }
    return 0;

}