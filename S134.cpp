#include <stdio.h>
//#include <conio.h>

int xuly(int x,int A)
{
    if(A == 0)
        return 0;
    int B = A, t = 0,mu10 = 1;
    while(B>=10)
    {
        B = B/10;
        t++;
        mu10 = mu10*10;
    }
    int y = A/mu10, a = (A - y*mu10);
    if(y<x)
         return y*t*(mu10/10) + xuly(x,a);
    else if(y>x)
         return mu10 + y*t*(mu10/10) + xuly(x,a);
    else if(y == x)
         return a+1+y*t*(mu10/10) + xuly(x,a);
}

int sochuso(int A)
{
    int KQ = 0;
    int B = A, t = 0,mu10 = 1;
    while(B>=10)
    {
        B = B/10;
        t++;
        mu10 = mu10*10;
    }
    for(int i = 1;i<=t;i++)
    {
        int nhan10 = 9*i;
        for(int j = 2;j<=i;j++)
            nhan10 = nhan10*10;
        KQ = KQ + nhan10;
    }
    KQ = KQ + (A-mu10+1)*(t+1);
    return KQ;
}

int main()
{
    int u[10],a,b;
    int tc; scanf("%d",&tc);
    while(scanf("%d %d",&a,&b)>0 && a>0)
    {
        if(a>b)
        {
            int temp = a;
            a = b;
            b = temp;
        }
        int hieu = 0;
        for(int i = 1;i<=9;i++)
        {
            u[i] = xuly(i,b)- xuly(i,a-1);
            hieu = hieu + u[i];
        }
        u[0] = sochuso(b) - sochuso(a-1) - hieu;
        for(int i = 0;i<=9;i++)
            printf("%d ",u[i]);
        printf("\n");
    }
   // getch();
}
