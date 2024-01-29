#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 
bool flag;
int n,a[15][15];
void Try(int i,int j,string s)
{
    if (i==n && j==n)
    {
        flag=true;
        cout<<s<<" ";
        return;
    }
    if (i<n && a[i+1][j]) Try(i+1,j,s+"D");
    if (j<n && a[i][j+1]) Try(i,j+1,s+"R");
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        flag=false;
        cin>>n;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++) cin>>a[i][j];
        if (!a[1][1] || !a[n][n]) 
        {
            cout<<"-1\n";
            continue;
        }
        Try(1,1,"");
        if (!flag) cout<<"-1\n";
        else cout<<"\n";
    }
}

