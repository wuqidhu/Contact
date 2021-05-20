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
		printf("ͨѶ¼�������޷����ӡ�\n");
	}
	else
	{
		printf("���������֣�");
		scanf("%s", ps->data[ps->size].name);
		printf("�������Ա�");
		scanf("%s", ps->data[ps->size].sex);
		printf("���������䣺");
		scanf("%d", &(ps->data[ps->size].age));
		printf("������绰��");
		scanf("%s", ps->data[ps->size].tele);
		printf("�������ַ��");
		scanf("%s", ps->data[ps->size].addr);
		ps->size++;
		printf("��ӳɹ�.\n");
		ShowContact(ps);
	}
}
void ShowContact(const struct Contact* ps)
{
	int i = 0;
	
	if (ps->size==0)
	{
		printf("����ϵ��\n");
	}
	else
	{
		printf("%-4s\t%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "���","����", "�Ա�", "����", "�绰", "��ַ");
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
		printf("����ϵ��\n");
	}
	else
	{
		int del = 0;
		printf("��������Ҫɾ����ϵ�˵���ţ�");
		scanf("%d", &del);
		if (del>ps->size)
		{
			printf("�޸���ϵ��\n");
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
		printf("�޸���ϵ��\n");
	}
	else
	{
		char name[MAX_NAME];
		printf("������Ҫ�����˵�����:");
		scanf("%s", name);
		int i = 0;
		for (i = 0; i < ps->size; i++)
		{
			if (0 == strcmp(ps->data[i].name, name))
			{
				printf("%-4s\t%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "���", "����", "�Ա�", "����", "�绰", "��ַ");
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
		printf("����ϵ��\n");
	}
	else
	{
		int num = 0;
		printf("������Ҫ�޸��˵���ţ�");
		scanf("%d", &num);
		printf("�������޸ĺ����Ϣ:\n");
		printf("���������֣�");
		scanf("%s", ps->data[num - 1].name);
		printf("�������Ա�");
		scanf("%s", ps->data[num - 1].sex);
		printf("���������䣺");
		scanf("%d", &(ps->data[num - 1].age));
		printf("������绰��");
		scanf("%s", ps->data[num - 1].tele);
		printf("�������ַ��");
		scanf("%s", ps->data[num - 1].addr);
		printf("�޸ĳɹ�.\n");
		ShowContact(ps);
	}
}
void SortContact(struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("����ϵ��\n");
	}
	else
	{
		qsort(ps, ps->size, sizeof(ps->data[0]), memcmp);
		ShowContact(ps);
	}
}