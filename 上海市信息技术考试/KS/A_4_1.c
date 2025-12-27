#include<stdio.h>
int main()
{
    printf("请输入商品编号：");
    int n;
    scanf("%d",&n);
    printf("请输入商品数量：");
    int num;
    scanf("%d",&num);
    float x;
    if(num>=0&&n>=1&&n<=4)
    {
        if(n==1)
    {
        x=num*4.2;
        printf("购买%d商品%d件，共计%.1f元",n,num,x);
    }
    else if(n==2)
    {
        x=num*6.8;
        printf("购买%d商品%d件，共计%.1f元",n,num,x);

    }
        else if(n==3)
    {
        x=num*12.8;
        printf("购买%d商品%d件，共计%.1f元",n,num,x);

    }
        else if(n==4)
    {
        x=num*16.5;
        printf("购买%d商品%d件，共计%.1f元",n,num,x);

    }
    }

    else if((n<1||n>4)||(num<0))
        printf("输入商品号或数量错误！");
    return 0;
}
