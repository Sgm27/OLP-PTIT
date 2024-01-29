#include <bits/stdc++.h>
using namespace std;
int a[5][5],tmp[5][5],b[5][5],x[25],res=INT_MAX;
bool ok=false;
void input()
{
	for (int i=1;i<=4;i++)
		for (int j=1;j<=4;j++) 
		{
			char x;
			cin>>x;
			if (x=='w') a[i][j]=0;
			else a[i][j]=1;
		}
}
bool check()
{
	int tmp1=b[1][1];
	for (int i=1;i<=4;i++)
		for (int j=1;j<=4;j++) 
			if (tmp1!=b[i][j]) return false;
	return true;
}
void process()
{
	int k=0,cnt=0;
	for (int i=1;i<=4;i++) 
		for (int j=1;j<=4;j++) 
		{
			k++;
			tmp[i][j]=x[k];
			b[i][j]=a[i][j];
		}
	for (int i=1;i<=4;i++)
		for (int j=1;j<=4;j++)
			if (tmp[i][j])
			{
				cnt++;
				if (b[i][j]==1) b[i][j]=0; else b[i][j]=1;
				if (b[i-1][j]==1) b[i-1][j]=0; else b[i-1][j]=1;
				if (b[i+1][j]==1) b[i+1][j]=0; else b[i+1][j]=1;
				if (b[i][j-1]==1) b[i][j-1]=0; else b[i][j-1]=1;
				if (b[i][j+1]==1) b[i][j+1]=0; else b[i][j+1]=1;
			}
	if (check())
	{
		ok=true;
		res=min(res,cnt);
	}
}
void thu(int i)
{
	for (int j=0;j<=1;j++)
	{
		x[i]=j;
		if (i==16) process(); 
		else thu(i+1);
	}
}
int main()
{
	// freopen("thu.inp","r",stdin);
	input();
	thu(1);
	if (!ok) cout<<"-1";
	else cout<<res;
}
