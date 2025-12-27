#include <stdlib.h>
#include <stdio.h>
struct event
{ //选手参赛信息
	char cname[20]; //比赛项目名称
	int ranking;    //该项目中名次
	int points;     //积分
};
struct contestant
{ //选手信息
	char pname[20];     //选手姓名
	struct event e[3];  //选手参赛表
	int totalpoints;    //总积分
};
void getpoints(struct contestant c[], int n)
{ //根据各选手排名计算对应积分，第1名2*n分，每降一名积分少2分
	//补充填写代码......
	for (int i = 0; i < n; i++)
	{
		c[i].e[0].points = (n + 1 - c[i].e[0].ranking) * 2;
		c[i].e[1].points = (n + 1 - c[i].e[1].ranking) * 2;
		c[i].e[2].points = (n + 1 - c[i].e[2].ranking) * 2;
	}
}
void gettotalpoints(struct contestant c[], int n)
{ //计算各选手总积分
	//补充填写代码......
	for (int i = 0; i < n; i++)
	{
		c[i].totalpoints = c[i].e[0].points + c[i].e[1].points + c[i].e[2].points;
	}
}
int main(void)
{
	int i, j;
	struct contestant c[5] = {
		{"zhao",{{"cooking",2,0},{"carving",3,0},{"cold_dishes",4,0}},0},
		{"qian",{{"cooking",3,0},{"carving",4,0},{"cold_dishes",5,0}},0},
		{"sun", {{"cooking",5,0},{"carving",5,0},{"cold_dishes",3,0}},0},
		{"li",  {{"cooking",4,0},{"carving",1,0},{"cold_dishes",2,0}},0},
		{"zhou",{{"cooking",1,0},{"carving",2,0},{"cold_dishes",1,0}},0} };
	getpoints(c, 5);
	gettotalpoints(c, 5);
	//补充填写代码......要求调用函数实现功能
	printf("序号\t姓名\t积分\n");
	for (i = 0; i < 5; i++)
		printf("%d\t%s\t%d\n", i + 1, c[i].pname, c[i].totalpoints);
	return 0;
}
