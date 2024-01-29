#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 1003
int n,q,a[maxn],r[maxn];
vector<int> v;
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>q;
    v.push_back(1);
    for (int i=2;i<=n;i++) 
    {
        cin>>a[i];
        v.insert(v.begin()+a[i],i);
    }
    for (int i=0;i<v.size();i++) r[v[i]]=i+1;
    while (q--)
    {
        int x;
        cin>>x;
        cout<<r[x]<<"\n";
    }
}
