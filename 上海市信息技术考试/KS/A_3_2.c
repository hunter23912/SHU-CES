#include<stdio.h>
int sum(int x[],int i1,int i2)//
{
    int i,s=0;//
    for(i=i1; i<=i2; i++)
        s=s+x[i];
    return s;
}
int main(void)
{
    int i,i1,i2,result;
    int x[10]= {12,23,21,34,40,6,15,18,45};
    printf("input a number: ");
    scanf("%d",&x[9]);
    printf("Input i1 and i2 :");
    scanf("%d%d",&i1,&i2);
    if(i1>=0 && i2<10)//
    {
        result=sum(x,i1,i2);
        printf("Sum=%d\n",result );
    }
    else
        printf("输入数据出错\n");
    return 0;
}
