#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;


int max(int a,int b)
{
    if (a>b) return a;
    return b;
}
int min(int a,int b)
{
    if (a>b) return b;
    return a;
}
int process(char s[])
{
    int dp[55],n=strlen(s);
    dp[0]=1;
    dp[1]=1;
    if (s[0]=='0') return 0;
    for (int i=2;i<=n;i++)
    {
        dp[i]=0;
        int k;
        char x1[55]="",x2[55]="";
        if (s[i-1]!='0') dp[i]=dp[i-1];
        strncpy(x2,s+i-2,2);
        k=atoi(x2);
        if (k>=10 && k<=26) dp[i]+=dp[i-2];
    }
    return dp[n];
}

int main()
{
    // freopen("thu.inp","r",stdin);
    int tc;
    scanf("%d",&tc);
    while (tc--)
    {
        char s[55];
        scanf("%s",s);
        printf("%d\n",process(s));
    }
}
