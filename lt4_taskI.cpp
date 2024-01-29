#include <bits/stdc++.h>
using namespace std;
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
int l,h;
int ans;
string p;
vector<int> v;
int isPrime(int k)
{
	if (k <= 1)
		return 0;
	if (k==2 || k==3)
		return 1;

	if (k % 2 == 0 || k % 3 == 0)
		return 0;
	for (int i = 5; i * i <= k; i = i + 6)
		if (k % i == 0 || k % (i + 2) == 0)
			return 0;

	return 1;
}

vector<int> nThPrime(int n)
{
    int i=2;
    vector<int> pri;
    while(n>0)
    {
        if(isPrime(i))
        {
            n--;
            pri.push_back(i);
        }
        i++;
    }
    i-=1; 
    pri.push_back(i);
    return pri;
}
void process()
{
    for (int i=l-1;i<=h-1;i++)
    {
        string t=to_string(v[i]);
        if (t.size()<p.size()) continue;
        for (int j=0;j<t.length()-p.length()+1;j++)
            if (t.substr(j,p.length())==p) 
            {
                ans++;
                break;
            }
    }
    cout<<ans;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>l>>h>>p;
	v=nThPrime(h);
    process();
    // cerr<<"\n"<<TIME;
}
