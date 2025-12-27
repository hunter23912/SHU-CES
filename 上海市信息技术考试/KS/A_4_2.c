#include<stdio.h>
#include<string.h>
int main()
{
    printf("请输入字符串：\n");
    char a[100];
    gets(a);
    printf("请输入子串：\n");
    char b[100];
    gets(b);
    int i;
    int flag=0;
    int j=0;
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]==b[j]&&a[i+1]!=' ')
        {
            flag=1;
            a[i]='*';
            j++;
        }
        else if(a[i]==b[j]&&a[i+1]==' ')
        {
            a[i]='*';
            break;
        }
    }
    if(flag==1)
    {
        printf("处理后的字符串：\n");
        puts(a);
    }
    else if(flag==0)
        printf("不存在该子串");
    return 0;
}
