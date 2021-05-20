#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

void menu()
{
	printf("*********************************************\n");
	printf("********  1.添加             2.删除  ********\n");
	printf("********  3.查找             4.修改  ********\n");
	printf("********  5.显示             6.排序  ********\n");
	printf("********  0.退出                     ********\n");
	printf("*********************************************\n");
}


int main()
{
	int input = 0;
	struct Contact con;//创建通讯录
	InitContact(&con);//初始化通讯录
	do
	{
		menu();
		printf("请选择： ");
		scanf("%d", &input);
		switch (input)
		{
		case exit:
			printf("退出通讯录!\n");
			break;
		case add:
			AddContact(&con);
			break;
		case del:
			DelContact(&con);
			break;
		case search:
			SearchContact(&con);
			break;
		case modify:
			ModifyContact(&con);
			break;
		case show:
			ShowContact(&con);
			break;
		case sort:
			SortContact(&con);
			break;
		default:
			printf("请重新选择!\n");
			break;
		}
	} while (input);
	return 0;
}