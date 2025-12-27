#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
   int no;//楼号
   int id;//室
   int old;//老人
   int adult;//成人
   int child;//孩子
}datatype;
int main(void)
{
   char admin[20]="admini",input_name[20];
   char pw[20]="ad123456",input_pw[20];
   int count=3;
   do{
      printf("请输入用户名:");
      gets(input_name);
      printf("请输入密码:");
      gets(input_pw);
      if(!strcmp(admin,input_name)||!strcmp(pw,input_pw))
      {
          printf("登录成功!");
          break;
      }
      else
      {
          printf("用户名或密码错误\n");
          count=count-1;
          if(count=0)
             printf("还有%d次机会\n",count);
          else
             printf("输入错误3次，系统关闭！");
      }
   }while(count>0)
   return 0;
}
