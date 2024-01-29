#include<bits/stdc++.h>
using namespace std;
typedef pair <int, int> ii;
#define fi                 first
#define se             second
#define pb             push_back
#define int long long
struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};
int n;
int a[100005];
int ans[100005];
vector<int>vt[100005];
signed main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("thu.inp", "r", stdin);
    //freopen(".out", "w", stdout);
    cin>>n;
    FenwickTree F(n+5);
    long long res=0;
    vector<int>kq;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]++;
        ans[i]=F.sum(a[i]+1,n+1);
        res+=ans[i];
        F.add(a[i],1);
        vt[a[i]].push_back(i);
    }
    //kq.push_back(res);
    for (int i=n;i>=1;i--)
    {
        for (auto j:vt[i])
            res-=ans[j];
        kq.push_back(res);
    }
    reverse(kq.begin(),kq.end());
    for (auto x:kq)
        cout<<x<<'\n';

    return 0;

}