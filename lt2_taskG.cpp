#include <bits/stdc++.h>
using namespace std;
int k;
string n;
int main()
{
	// freopen("thu.inp","r",stdin);
	cin>>n>>k;
	stack<char> s;
	for (int i=0;i<=n.length()-1;i++)
	{
		char x=n[i];
		if (s.empty()) s.push(x);
		else
		{
			while (!s.empty() && s.top()<x && k>0)
			{
				s.pop();
				k--;
			}
			s.push(x);
		}
	}
	while (k>0 && !s.empty())
	{
		s.pop();
		k--;
	}
	vector<char> v;
	while (!s.empty())
	{
		v.push_back(s.top());
		s.pop();
	}
	for (int i=v.size()-1;i>=0;i--) cout<<v[i];
}