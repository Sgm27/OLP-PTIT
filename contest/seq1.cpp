#include<bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 1000006
int n,a[maxn];
struct node{
    int pre,suf,sum,maxsum;
};
node Merge(node l,node r)
{
    node res;
    res.pre=max(l.pre,l.sum+r.pre);
    res.suf=max(r.suf,l.suf+r.sum);
    res.sum=l.sum+r.sum;
    res.maxsum=max({l.maxsum,r.maxsum,l.suf+r.pre});
    return res;
}
node get(int l,int r)
{
    if (l==r) return {a[l],a[l],a[l],a[l]};
    int m=(l+r)/2;
    return Merge(get(l,m),get(m+1,r));
}
signed main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    cout<<get(1,n).maxsum;
}

