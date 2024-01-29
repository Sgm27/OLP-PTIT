#include <bits/stdc++.h>
using namespace std;
int n,k;
int main()
{
	// freopen("thu.inp","r",stdin);
	string st;
    cin>>st>>k;
    int n=st.length(); st=" "+st;
	stack<char> s;
	for (int i=1;i<=n;i++)
	{
		char x=st[i];
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