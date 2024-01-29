#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 
string s,t;
int n,cnt[10];
void process()  
{
    memset(cnt,0,sizeof(cnt));
    int Mau_moi[20];
    for (char c : t)
        cnt[c-'0']++;
    int T=stoll(t),S=stoll(s);
    
    int BIT=INF,ans=S,MAU=T;
    for (int mask=1;mask<(1<<n);mask++)
    {
        string tmp="";
        int so_bit=__builtin_popcountll(mask);
        int d[10]={},CHECK=true;
        memset(d,0,sizeof(d));
        for (int i=0;i<n;i++)
            if ((mask>>i)&1) 
                tmp+=s[i];
            else 
            {
                d[s[i]-'0']++;
                if (d[s[i]-'0']>cnt[s[i]-'0']) 
                {
                    CHECK=false;
                    break;
                }
            }
        if (!tmp.size()) continue;
        int st=stoll(tmp);
        if (!st || st>=ans || !CHECK) continue;
        int G=__gcd(T,S);
        T/=G, S/=G;
        cout<<S<<" "<<T<<"\n"
        int Mau=st*T/S; // mau=t*st/s;  
        int R=0;
        int T_mau=Mau,idx=0;
        while (T_mau)
        {
            Mau_moi[idx++]=T_mau%10;
            T_mau/=10;
        }
        idx--;
        bool flag=true;
        for (int j=idx;j>=0;j--)
        {
            bool check=false;
            while (R<t.length())
            {
                if (t[R]-'0'==Mau_moi[j])
                {
                    check=true;
                    R++;
                    break;
                }
                else 
                {
                    d[t[R]-'0']--;
                    R++;
                }
            } 
            flag &= check;
            if (!flag) break;
        }
        if (flag) 
        {
            while (R<t.length()) d[t[R++]-'0']--; 
            for (int k=0;k<=9;k++)
                if (d[k]!=0) flag=false;
        }
        if (flag && ans>st)
        {
            BIT=min(BIT,so_bit);
            ans=st;
            MAU=Mau;
        }
    }
    if (ans!=INF)
        cout<<ans<<" "<<MAU<<"\n";
    
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    freopen("thu.out","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>s>>t;
        n=s.length();
        process();
    }
}