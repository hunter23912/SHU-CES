#include <stdio.h>
int main(void)
{
    int k,s=1,n;
    int sum=0;//
    printf("input n: ");
    scanf("%d",&n);
    for(k=1; k<=n; k++)//
    {
        s=s*k;
        sum+=s;
    }
    for(k=1; k<=n; k++)
        sum=sum+k*k;//
    printf("%d\n",sum);
    return 0;
}
