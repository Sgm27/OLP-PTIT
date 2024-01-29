#pragma GCC optimize("O2")
#include <iostream>
#include<deque>
using namespace std;
#define int int32_t
int n, q;
int u, v, c;
int a[1005];
int f[1005];
int ans[100005];
signed main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        char c;
        scanf(" %c",&c);
        a[i] = c - '0';
    }
    while (q--) {
        scanf("%d%d%d", &u, &v, &c);
        if (u > v) swap(u, v);
        if (v-u <= c)
        {
            printf("%d\n",a[u]+a[v]);
            continue;
        }
        int s = u;
        int t = v;
        deque<int>dq;
        f[s] = a[s];
        dq.push_back(s);
        for (int i = s+1; i <= t; ++i)
        {
            while (dq.size() && dq.front() + c < i) dq.pop_front();
            f[i] = f[dq.front()] + a[i];
            while (dq.size() && f[dq.back()] >= f[i]) dq.pop_back();
            dq.push_back(i);
        }
        printf("%d\n", f[t]);
    }
}