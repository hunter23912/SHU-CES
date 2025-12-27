#include "head.h"
void mainMenu(void);            /* 显示主菜单 */
sNode* loadInfo(sNode* h);     /* 加载信息函数*/
void displayInfo(sNode* h);     /* 显示信息函数*/
sNode* delInfo(sNode* h);      /* 删除信息函数*/

//sNode* loadInfo(sNode* h)
//{
//	const char* filename = "D:\\Desktop\\KS\\A_6_1.txt";
//	FILE* file = fopen(filename, "r");
//	if (file == NULL)
//	{
//		printf("无法打开文件\n");
//		return h;
//	}
//	sNode* current = h;
//	while (1)
//	{
//		sNode* newStudent = (sNode*)malloc(sizeof(sNode));
//		if (fscanf(file, "%s%s%f", newStudent->no, newStudent->name, &newStudent->score) != 3)
//		{
//			printf("信息加载成功！");
//			break;
//		}
//		newStudent->next = NULL;
//		if (current == NULL)
//		{
//			h = newStudent;
//			current = newStudent;
//		}
//		else
//		{
//			while (current->next != NULL)
//			{
//				current = current->next;
//			}
//			current->next = newStudent;
//			current = newStudent;
//		}
//	}
//	fclose(file);
//	return h;
//}
sNode* loadInfo(sNode* h)
{
	const char* filename = "D:\\Desktop\\KS\\A_6_1.txt";
	FILE* file = fopen(filename, "r");
	if (file == NULL)
	{
		printf("文件打开失败\n");
		return h;
	}
	sNode* current = h;
	while (1)
	{
		sNode* newStudent = (sNode*)malloc(sizeof(sNode));
		if (fscanf(file, "%s%s%f", newStudent->no, newStudent->name, &newStudent->score) != 3)
		{
			printf("信息加载成功！\n");
			break;
		}
		if (h == NULL)
		{
			h = newStudent;
			newStudent->next = NULL;
			current = newStudent;
		}
		else
		{
			newStudent->next = current;
			h = newStudent;
			current = newStudent;
		}
	}
	fclose(file);
	return h;
}

void displayInfo(sNode* h)
{
	sNode* current = h;
	printf("\n学生信息：\n");
	if (current == NULL)
		printf("信息为空\n");
	printf("------------学生信息------------\n");
	printf("     学号     姓名     分数\n");
	while (current != NULL)
	{
		printf("    %s    %s    %.2f\n", current->no, current->name, current->score);
		current = current->next;
	}
}

//sNode* findNode(sNode* h, const char* target)
//{
//	sNode* current = h;
//	while (current != NULL)
//	{
//		if (strcmp(current->no, target) == 0)
//		{
//			return current;
//		}
//		current = current->next;
//	}
//	return NULL;
//}
sNode* FindInfo(sNode* h, const char* target)
{
	sNode* current = h;
	while (current != NULL)
	{
		if (strcmp(current->no, target) == 0)
		{
			return current;
		}
		current = current->next;
	}
	printf("查无此号！\n");
	return NULL;
}


//sNode* delInfo(sNode* h)
//{
//	char target[6];
//	printf("待删信息学号：");
//	scanf("%s", target);
//	sNode* current = h;
//	sNode* prev = NULL;
//	while (current != NULL)
//	{
//		if (strcmp(current->no, target) == 0)
//		{
//			if (prev == NULL)
//			{
//				h = current->next;
//			}
//			else
//			{
//				prev->next = current->next;
//			}
//			free(current);
//			printf("删除成功\n");
//			return h;
//		}
//		prev = current;
//		current = current->next;
//	}
//	printf("未找到学号为%s的学生信息。\n", target);
//	return h;
//}
sNode* delInfo(sNode* h)
{
	printf("----------删除信息----------\n");
	printf("待删信息学号：");
	char a[6];
	scanf("%s", a);
	sNode* current = h, * target, * pre = NULL;
	target = FindInfo(h, a);
	if (target != NULL)
	{
		printf("    学号    姓名    分数\n");
		printf("    %s    %s    %.2f\n", target->no, target->name, target->score);
		getchar();
		char c;
		printf("删除确认(Y/N):");
		scanf("%c", &c);
		printf("(%c)已成功输入字符\n", c);
		if (c == 'y' || c == 'Y')
		{
			while (current != NULL)
			{
				if (current == target)
				{
					if (pre == NULL)
					{
						h = current->next;
					}
					else
					{
						pre->next = current->next;
					}
					free(current);
					printf("删除成功\n");
					return h;
				}
				pre = current;
				current = current->next;
			}
		}
		else if (c == 'N' || c == 'n')
		{
			printf("删除已取消！\n");
		}
		else
			printf("输入错误，程序返回\n");
	}
	else
	{
		printf("删除失败！\n");
	}
	return h;
}


int main(void)
{
	sNode* head = NULL;        /* 链表结构头指针，作为头指针 */
	int ch;
	while (1)
	{
		mainMenu();
		printf("请选择(0-3):");
		scanf("%d", &ch);
		switch (ch)
		{
		case 0:     //命令0
			return 0;
		case 1:     //命令1
			head = loadInfo(head);
			break;
		case 2:     //命令2
			displayInfo(head);
			break;
		case 3:     //命令3
			head = delInfo(head);
			break;
		default:    //无效命令，过滤至换行
			scanf("%*[^\n]%*c");
		}
	}
	return 0;
}

void mainMenu(void)
{
	printf("\n************************学生成绩管理**************************\n\n");
	printf("  1. 载入信息\t2. 显示信息\t3. 删除信息\t0. 退出系统\n");
	printf("\n**************************************************************\n");
}
