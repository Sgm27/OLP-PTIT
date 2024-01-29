#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second
#define sz(x) ((int)(x).size())
typedef long long ll;
 
#ifndef ONLINE_JUDGE
#define deb(x) cout<<#x<<" "<<x<<"\n"
#define deb2(x,y) cout<<"[ "<<#x<<"="<<x<<","<<#y<<"="<<y<<" ]\n"
#define deba(x,n) cout<<#x<<": [ ";for(int i=0;i<n;i++){cout<<x[i]<<" ";}cout<<"]\n"; 
#define deba2(x,n,m) cout<<#x<<":\n";for(int i=0;i<n;i++){for(int j=0;j<m;j++)cout<<x[i][j]<<" ";cout<<"\n";}; 
#define debe(x) cout<<#x<<":[ ";for(auto i:x){cout<<i<<" ";}cout<<"]\n"; 
#else
#define deb(x) 
#define deb2(x,y) 
#define deba(x,n) 
#define deba2(x,n,m) 
#define debe(x) 
#endif
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        int n;
        cin>>n;
        vector<array<int,2>>points(n);
        for(int i=0;i<n;i++){
            cin>>points[i][0]>>points[i][1];
        }
        vector<array<ll,2>>line;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                line.pb({points[i][0]+points[j][0],points[i][1]+points[j][1]});
            }
        }
        sort(all(line));
        ll ans=0;
        int cnt=1;
        for(int i=1;i<sz(line);i++)
        {
            if(line[i]==line[i-1])
            {
                ++cnt;
            }
            else
            {
                ans+=1LL*cnt*(cnt-1)/2;
                cnt=1;
            }
        }
        ans+=(1LL*cnt*(cnt-1))/2;
        cout<<ans<<"\n";	
    }
    return 0;
}