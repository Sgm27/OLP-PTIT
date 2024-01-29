#include <iostream>
#include <cstdlib>
#include <time.h> 
#include<map>
using namespace std;
#define int long long
long long GetRandom(long long Min,long long Max){
    return Min + (long long)(rand()*(Max-Min+1.0)/(1.0+RAND_MAX));
}

signed main(){
	freopen("thu.inp","w",stdout);
    srand(time(NULL));
    long long Min = 1, Max = 10000,m1=1,m2=1e1;
    long long n=10;
    long long k=GetRandom(15,20);
    map<pair<int,int>,int> mp;
    // cout<<1<<"\n"<<k<<"\n";
    cout<<n<<" "<<k<<"\n";
    for (int t=1;t<=3*k;t++)
    {
        // cout<<"10\n";
        // for (int i = 0;i < n;i++) {
            long long t1=GetRandom(1,2);
            long long t2=GetRandom(1,n);
            long long t3=GetRandom(1,n);
            long long t4=GetRandom(Min,Max);
            // if (t1<t2) cout<<t1<<" "<<t2<<"\n";
            if (t2<=t3) cout<<t1<<" "<<t2<<" "<<t3<<"\n";
            
        }
        cout<<"\n";
    // }
    // cout<<0;
    // }
    return 0;
}

