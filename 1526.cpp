#include<iostream>
#include<unordered_map>
#include<queue>
#include<set>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define pii pair<int,int>
#define maxn 100005
string a[maxn];
set<int> se;
unordered_map<string,int> D;
bool check(string s1,string s2)
{
    int count=0;
    FOR(i,0,s1.length()-1)
        if (s1[i]!=s2[i]) count++;
    return count==1;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        int n;
        string s,t;
        cin>>n>>s>>t;
        FOR(i,1,n) 	cin>>a[i], se.insert(i);
        queue<string> Q;
        Q.push(s);
        bool flag=false;
        while (!Q.empty())
        {
            vector<int> v;
            string x=Q.front();
            Q.pop();
            for (int i : se)
                if (!D[a[i]] && check(x,a[i]))
                {
                    v.push_back(i);
                    Q.push(a[i]);
                    D[a[i]]=D[x]+1;
                    if (D[t]) 
                    {
                        flag=true;
                        break;
                    }
                }
            for (int x : v) se.erase(x);
            if (flag) break;
        }
        cout<<D[t]+1<<"\n";
    }
}
