//cnNum02，输入一或两位整数，输出对应的中文数字串
#include <stdio.h>
void prtChnNum1(int n)
{ //输出数字n对应的中文汉字，整数n取值：0-9,10
    switch (n)
    {
        case 0:  printf("零");  break;
        case 1:  printf("一");  break;
        case 2:  printf("二");  break;
        case 3:  printf("三");  break;
        case 4:  printf("四");  break;
        case 5:  printf("五");  break;
        case 6:  printf("六");  break;
        case 7:  printf("七");  break;
        case 8:  printf("八");  break;
        case 9:  printf("九");  break;
        case 10: printf("十");  break;
        default: printf("×");  break;
    }
} //本行及以上代码不含错误
int main(void)
{ //主函数
    int n, a1, a2;
    scanf("%d",  n); //n为输入数
    a1 = n%10;       //个位数
    a2 = n/10 % 10;  //十位数
    if (n<0 && n>=100)
        printf("无效");
    else if (n==0)
        prtChnNum1(0);
    else
    {
        if (a2>=1)
        {
            prtChnNum1(a2); //输出十位数
            prtChnNum1(10); //输出“十”
        }
        if (a1>=0)
            prtChnNum1(a1); //输出个位数
    }
    printf("\n");           //程序结束前“换行”
    return 0;
}
