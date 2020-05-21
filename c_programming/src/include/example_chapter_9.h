#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

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
		char detail[256];	//
	} address;

	// score

	// friendships

	// neighbors

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
// �ҵ�����ָ�룬�������򷵻�0
Student * find_student(Student *p, int n, char *target_number)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (strcmp(p[i].number, target_number) == 0)	// ��αȽ��ַ���
		{
			// print_student(&p[i]);
			return &p[i];
		}
	}
	return 0;
}

void update_student(Student *p)
{
	printf("rename %s to ", p->name);
	scanf("%s", p->name);
	printf("revise gender '%s' to ", p->gender);
	scanf("%s", p->gender);
}

void sort_sutdent_by_number(Student *students, int n)
{
	int i; // ��ǰ��i������С
	int j;	// ��ǰ����������Ҫ���н�������
	Student temp;

	for (i = 0; i < n - 1; i++)
	{
		int index = i;
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(students[index].number, students[j].number) > 0)
			{
				index = j;
			}
		}
		if (index > i)	//
		{
			temp = students[i];
			students[i] = students[index];
			students[index] = temp;
		}
	}
}

void sort_sutdent_by_name(Student *students, int n)
{
	int i; // ��ǰ��i������С
	int j;	// ��ǰ����������Ҫ���н�������
	Student temp;

	for (i = 0; i < n - 1; i++)
	{
		int index = i;
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(students[index].name, students[j].name) > 0)
			{
				index = j;
			}
		}
		if (index > i)	//
		{
			temp = students[i];
			students[i] = students[index];
			students[index] = temp;
		}
	}
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
	printf("5. ��ѧ�Ÿ���ָ��ѧ����Ϣ\n");
	printf("6. ��ѧ����������ѧ����Ϣ\n");
	printf("7. ��������������ѧ����Ϣ\n");
	printf("0. �˳�����\n");
	printf("input your choice: ");
}

void menu(Student *students, int *p_n, int choice)
{
	int i;
	Student *p = 0;
	char target_number[13] = {0};

	switch (choice)
	{
	case 1:
		printf("input the number of students (n): ");
		scanf("%d", p_n);
		for (i = 0; i < *p_n; i++)
		{
			read_student(&students[i]);
		}
		break;
	case 2:
		for (i = 0; i < *p_n; i++)
		{
			print_student(&students[i]);
		}
		if (*p_n == 0)
		{
			printf("no student records.\n");
		}
		break;
	case 3:
		printf("input student number (no.): ");
		scanf("%s", target_number);
		p = find_student(students, *p_n, target_number);	// the simplest design
		if (p != 0)
		{
			print_student(p);
		}
		else
		{
			printf("can't find student with number %s.\n", target_number);
		}
		break;
	case 4:
		read_student(&students[*p_n]);
		*p_n += 1;
		break;
	case 5:
		printf("input student number (no.): ");
		scanf("%s", target_number);
		p = find_student(students, *p_n, target_number);
		if (p != 0)
		{
			update_student(p);
		}
		else
		{
			printf("can't find student with number %s.\n", target_number);
		}
		break;
	case 6:
		sort_sutdent_by_number(students, *p_n);
		for (i = 0; i < *p_n; i++)
		{
			print_student(&students[i]);
		}
		break;
	case 7:
		sort_sutdent_by_name(students, *p_n);
		for (i = 0; i < *p_n; i++)
		{
			print_student(&students[i]);
		}
		break;
	default:
		break;
	}

}