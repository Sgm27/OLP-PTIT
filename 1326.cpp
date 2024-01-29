#include<iostream>
using namespace std;
using ll = long long;
ll f[93],n,k;
void init()
{
    f[1]=f[2]=1;
    for (int i=3;i<=92;i++) f[i]=f[i-1]+f[i-2];
}
void process()
{
    int cs=n;
    while (cs>2)
    {
        if (k<=f[cs-2]) 
        {
            cs-=2;
            continue;
        }
        k-=f[cs-2];
        cs--;
    }
    if (cs==1) cout<<"A\n";
    else cout<<"B\n";
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    init();
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n>>k;	
        process();
    }
}

