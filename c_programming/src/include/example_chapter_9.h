#pragma once

#include<string.h>
#include<memory.h>

// typedef�����ض���
typedef struct  {
	// basic information
	char number[13];		// e.g., 201921145022
	char name[4 * 2 + 2];	// �4������
	char gender[2 * 1 + 2];	// {'��', 'Ů'}

	// address
	struct
	{
		double longitude;	// 
		double latitude;	// 
		char detail[256];	// ����ʡ������
	} address;

	

} Student;	// �����ƣ������Ժ����ӳ�Ա����������Ҫ����޸���ǰ�ĺ���


void read_student(Student *p)
{
	printf("������ѧ�ţ�");
	scanf("%s", p->number);
	printf("������������");
	scanf("%s", p->name);
	printf("�������Ա�");
	scanf("%s", p->gender);

	// TODO
}

void print_student(Student *p)
{
	printf("%s\t%s\t%s\n", p->number, p->name, p->gender);
}

// �Ӻܶ��ѧ���������һ��ѧ��
// �����������ҵ�һ��Ŀ�����
Student * find_student(Student *p, int n, char *target_number)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (strcmp(p[i].number, target_number) == 0)	// ��αȽ��ַ���
		{
			print_student(&p[i]);
			return &p[i];
		}
	}
	printf("δ�ҵ�ѧ�ţ�%s\n", target_number);
	return 0;
}

void update_student(Student *p)
{
	printf("��������޸ĵ�������");
	scanf("%s", p->name);
}

void delete_student(Student *p, int n, char *number)
{

}

void show_tips()
{
	printf("1. �������ɸ�ѧ����Ϣ\n");
	printf("2. ��ʾ���ɸ�ѧ����Ϣ\n");
	printf("3. ��ѧ�Ų��Ҳ���ʾѧ����Ϣ\n");
	printf("4. ����һ��ѧ����Ϣ\n");
	printf("0. �˳�����\n");
}

void menu(int sel)
{
	int n, i;
	Student students[200], *p = 0;
	char target_name[13] = {0};

	switch (sel)
	{
	case 1:
		printf("�������ѧ������: ");
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			read_student(&students[i]);
		}
		break;
	case 2:
		// display all
		for (i = 0; i < n; i++)
		{
			print_student(&students[i]);
		}
		break;
	case 3:
		printf("������ѧ��: ");
		scanf("%s", target_name);
		p = find_student(students, n, target_name);
		break;

	default:
		break;
	}

}