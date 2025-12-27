#include <stdio.h>
#include <string.h>
#define N 7
struct d_list           //家庭收支记录
{
    char detail[11];    //明细
    char ttype[10];     //类型：收入或支出
    float  count;       //金额
    long   date;        //年月日
} ;
float income=0.0;

float in_out_count( struct d_list p[],int n)//
{
    int i;
    float out=0.0;
    for (i=0; i<n; i++)//
        if (strcmp(p[i].ttype,"收入")==0)//
            income=income+p[i].count;
        else
            out=out+p[i].count;
return out;

}
int main(void)
{
    struct d_list d_info[N]= {{"工资","收入",14572.80,20220110},
        {"交房租","支出",4000,20220105},{"买衣服","支出",320,20220115},
        {"奖金","收入",3000,20220120},	{ "交水电费","支出",235.60,20220120},
        {"买米面","支出",346.0,20220125}
    };
    int i;
    float expend,total;
    printf("输入一条记录：明细、类型、金额和日期：");
    scanf("%s%s%f%d",d_info[N-1].detail,d_info[N-1].ttype,&d_info[N-1].count,&d_info[N-1].date);
    expend=in_out_count(d_info,N);
    total=income-expend;
    printf("%6s %6s %12s %8s %10s\n","序号","日期","明细","类型","金额");
    for(i=0; i<N; i++)
        printf("%4d %10ld %12s %6s %12.2f\n",i+1,d_info[i].date,d_info[i].detail,d_info[i].ttype,d_info[i].count);
    printf("%10s:%12.2f\t %10s:%12.2f %10s:%.2f\n","收入",income,"支出",expend,"收入余额",total);//
    return 0;
}
