#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

void InitContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;
}
void AddContact(struct Contact* ps)
{
	if (ps->size==MAX)
	{
		printf("通讯录已满，无法增加。\n");
	}
	else
	{
		printf("请输入名字：");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入性别：");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入年龄：");
		scanf("%d", &(ps->data[ps->size].age));
		printf("请输入电话：");
		scanf("%s", ps->data[ps->size].tele);
		printf("请输入地址：");
		scanf("%s", ps->data[ps->size].addr);
		ps->size++;
		printf("添加成功.\n");
		ShowContact(ps);
	}
}
void ShowContact(const struct Contact* ps)
{
	int i = 0;
	
	if (ps->size==0)
	{
		printf("无联系人\n");
	}
	else
	{
		printf("%-4s\t%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "序号","姓名", "性别", "年龄", "电话", "地址");
		for (i = 0; i < ps->size; i++)
		{
			printf("%-4d\t%-20s\t%-4s\t%-5d\t%-12s\t%-20s\n",
				i+1,
				ps->data[i].name, 
				ps->data[i].sex,
				ps->data[i].age,
				ps->data[i].tele,
				ps->data[i].addr);
			//printf("  %s  |", ps->data[i].name);
			//printf("  %s  |", ps->data[i].sex);
			//printf("  %d  |", ps->data[i].age);
			//printf("  %s  |", ps->data[i].tele);
			//printf("  %s  |", ps->data[i].addr);
		}
	}
}
void DelContact(struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("无联系人\n");
	}
	else
	{
		int del = 0;
		printf("请输入需要删除联系人的序号：");
		scanf("%d", &del);
		if (del>ps->size)
		{
			printf("无该联系人\n");
			return 0;
		}
		else
		{
			int j = 0;
			for ( j = del-1; j < ps->size; j++)
			{
				ps->data[j] = ps->data[j + 1];
			}
		}
		ps->size--;
		ShowContact(ps);
		//memset(ps->data+del-1, 0, sizeof(ps->data[0]) + sizeof(ps->size));

	}
}
void SearchContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("无该联系人\n");
	}
	else
	{
		char name[MAX_NAME];
		printf("请输入要查找人的名字:");
		scanf("%s", name);
		int i = 0;
		for (i = 0; i < ps->size; i++)
		{
			if (0 == strcmp(ps->data[i].name, name))
			{
				printf("%-4s\t%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "序号", "姓名", "性别", "年龄", "电话", "地址");
				printf("%-4d\t%-20s\t%-4s\t%-5d\t%-12s\t%-20s\n",
					i + 1,
					ps->data[i].name,
					ps->data[i].sex,
					ps->data[i].age,
					ps->data[i].tele,
					ps->data[i].addr);
			}
		}
	}
}
void ModifyContact(struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("无联系人\n");
	}
	else
	{
		int num = 0;
		printf("请输入要修改人的序号：");
		scanf("%d", &num);
		printf("请输入修改后的信息:\n");
		printf("请输入名字：");
		scanf("%s", ps->data[num - 1].name);
		printf("请输入性别：");
		scanf("%s", ps->data[num - 1].sex);
		printf("请输入年龄：");
		scanf("%d", &(ps->data[num - 1].age));
		printf("请输入电话：");
		scanf("%s", ps->data[num - 1].tele);
		printf("请输入地址：");
		scanf("%s", ps->data[num - 1].addr);
		printf("修改成功.\n");
		ShowContact(ps);
	}
}
void SortContact(struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("无联系人\n");
	}
	else
	{
		qsort(ps, ps->size, sizeof(ps->data[0]), memcmp);
		ShowContact(ps);
	}
}