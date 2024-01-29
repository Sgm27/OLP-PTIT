#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string s;
void process(string s)
{
	string x;
	if (s.length()>2) x=s.substr(s.length()-2,2);
	else x=s;
	int tmp=stoi(x);
	tmp%=4;
	if (tmp==0) cout<<"4\n";
	else cout<<"0\n";
}
int main()
{
	// freopen("thu.inp","r",stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int tc;
	cin>>tc;
	while (tc--)
	{
		cin>>s;
		process(s);
	}
}

