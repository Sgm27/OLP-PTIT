#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" ms"
#define int long long
#define pii pair<int,int>
#define maxn 100005
#define maxbit 20
int nnode,q,size;
struct trie{
    int child[2],exist,count;
    int val;
}   t[maxn*4];
void add(int k)
{
    int node=0;
    FOD(i,maxbit,0)
    {
        int id=(k>>i)&1;
        if (!t[node].child[id]) t[node].child[id]=++nnode;
        node=t[node].child[id];
        t[node].count++;
    }
    t[node].exist++;
    t[node].val=k;
}
void del(int k)
{
    int node=0;
    FOD(i,maxbit,0)
    {
        int id=(k>>i)&1;
        int tnode=t[node].child[id];
        t[tnode].count--;
        if (!t[tnode].count) 
        {
            t[node].child[id]=0;
            return;
        }
        node=tnode;
    }
}
int get(int k)
{
    int node=0;
    FOD(i,maxbit,0)
    {
        int left=t[node].child[0];
        if (left && t[left].count>=k) node=left;
        else
        {
            node=t[node].child[1];
            k-=t[left].count;
        }
    }
    return t[node].val;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>q;
    while (q--)
    {
        string type; cin>>type;
        if (type=="add") 
        {
            int k; cin>>k;
            size++;
            add(k);
        }
        else
        if (type=="del")
        {
            int k; cin>>k;
            size--;
            del(k);
        }
        else
            cout<<get((size+1)/2)<<"\n";    
    }
}
