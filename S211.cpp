#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
int stt=0;

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
void process(char s[])
{
    stt++;
    printf("Test %d: ",stt);
    char tmp[15]="I";
    strcat(tmp,s);
    strcpy(s,tmp);
    strcat(s,"I");
    int cs=0,l=1;
    while (l<strlen(s))
    {
        int cnt=0;
        while (s[l]=='D') 
        {
            cnt++;
            l++;
        }
        cs+=cnt+1;
        printf("%d",cs);
        int tmp=cs;
        while (cnt--) printf("%d",--tmp); 
        l++;
    }
    printf("\n");
}
int main()
{
    // freopen("thu.inp","r",stdin);
    int tc;
    scanf("%d",&tc);
    while (tc--)
    {
        char s[15];
        scanf("%s",s);
        process(s);
    }
}
