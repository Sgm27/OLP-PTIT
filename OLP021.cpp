#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 
const int max_bfs=1<<13;
string s,t="1238004765";
unordered_map<string,int> D,D1;
int m1[10]={3,0,2,7,4,1,6,8,5,9};
int m2[10]={0,4,1,3,8,5,2,7,9,6};
int m3[10]={1,5,2,0,4,8,6,3,7,9};
int m4[10]={0,2,6,3,1,5,9,7,4,8};
string turn_1(string s)
{
	string ans="";
	FOR(i,0,9)
		ans+=s[m1[i]];
	return ans;
}
string turn_2(string s)
{
	string ans="";
	FOR(i,0,9)
		ans+=s[m2[i]];
	return ans;
}
string turn_back1(string s)
{
	string ans="";
	FOR(i,0,9)
		ans+=s[m3[i]];
	return ans;
}
string turn_back2(string s)
{
	string ans="";
	FOR(i,0,9)
		ans+=s[m4[i]];
	return ans;
}
void bfs1(string s)
{
	int cnt_bfs=0;
	queue<string> Q;
	Q.push(s);
	D[s]=0;
	while (!Q.empty())
	{
		string x=Q.front();
		Q.pop();
		if (cnt_bfs++>max_bfs) return;
		string st;
		st=turn_back1(x);
		if (!D[st])
		{
			Q.push(st);
			D[st]=D[x]+1;
		}
		st=turn_back2(x);
		if (!D[st])
		{
			Q.push(st);
			D[st]=D[x]+1;
		}
	}
}
int bfs2(string s)
{
	if (D[s]) return D[s];
	queue<string> Q;
	Q.push(s);
	D1[s]=0;
	while (!Q.empty())
	{
		string x=Q.front();
		Q.pop();
		string st;
		st=turn_1(x);
		if (D[st]) return D1[x]+D[st]+1;
		else
		{
			Q.push(st);
			D1[st]=D1[x]+1;
		}
		st=turn_2(x);
		if (D[st]) return D1[x]+D[st]+1;
		else
		{
			Q.push(st);
			D1[st]=D1[x]+1;
		}
	}
}
signed main()
{
	#ifndef ONLINE_JUDGE
	freopen("thu.inp","r",stdin);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int tc; tc=1;
	while (tc--)
	{
		string s="";
		FOR(i,1,10)
		{
			char x; cin>>x;
			s+=x;
		}	
		if (s==t) 
		{
			cout<<"0\n";
			continue;
		}
		bfs1(t);
		cout<<bfs2(s)<<"\n";
		D1.clear();
		D.clear();
	}
}
	