#include <bits/stdc++.h>
using namespace std;
bool check[150];
struct mang{
	string bo,con;
	int tuoi;
};
struct ketqua{
	string ten;
	int tuoi;
};
mang a[150];
int tt=0;
ketqua kq[150];
bool cmp(ketqua a,ketqua b)
{
	if (a.tuoi!=b.tuoi) return a.tuoi<b.tuoi;
	else return a.ten>b.ten;
}
void process(mang a[],int n)
{
	map<string,int> mp;
	int cnt=n;
	memset(check,true,sizeof(check));
	for (int i=1;i<=n;i++)
		if (a[i].bo=="Ted") 
		{
			mp[a[i].con]=100-a[i].tuoi;
			check[i]=false;
			cnt--;
		}
	while (cnt)
	{
	for (pair<string,int> x : mp)
		for (int i=1;i<=n;i++)
			if(check[i] && a[i].bo==x.first)
			{
				check[i]=false;
				cnt--;
				mp[a[i].con]=x.second-a[i].tuoi;
			}
	}
	cout<<"DATASET "<<tt<<endl;
	int dem=0;
	for (pair<string,int> x : mp) 
		{
			dem++;
			kq[dem].ten=x.first;
			kq[dem].tuoi=x.second;
		}
	sort(kq+1,kq+1+dem,cmp);
	for (int i=dem;i>=1;i--) cout<<kq[i].ten<<" "<<kq[i].tuoi<<endl;
}
int main()
{
	// freopen("thu.inp","r",stdin);
	int tc;
	cin>>tc;
	while (tc--)
	{
		tt++;
		int n;
		cin>>n;
		for (int i=1;i<=n;i++) cin>>a[i].bo>>a[i].con>>a[i].tuoi;
		process(a,n);
	}
}

