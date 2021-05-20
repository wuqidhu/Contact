#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

void menu()
{
	printf("*********************************************\n");
	printf("********  1.���             2.ɾ��  ********\n");
	printf("********  3.����             4.�޸�  ********\n");
	printf("********  5.��ʾ             6.����  ********\n");
	printf("********  0.�˳�                     ********\n");
	printf("*********************************************\n");
}


int main()
{
	int input = 0;
	struct Contact con;//����ͨѶ¼
	InitContact(&con);//��ʼ��ͨѶ¼
	do
	{
		menu();
		printf("��ѡ�� ");
		scanf("%d", &input);
		switch (input)
		{
		case exit:
			printf("�˳�ͨѶ¼!\n");
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
			printf("������ѡ��!\n");
			break;
		}
	} while (input);
	return 0;
}