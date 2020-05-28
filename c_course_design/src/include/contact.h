#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>
// windows (default): D:\\study\\teaching\\2020�� C����-��ѧԺ19��\\contacts.csv
// macos or linux: "D:/study/teaching/2020�� C����-��ѧԺ19��/contacts.csv"
// �ֶΣ�"ѧ��,����,�Ա�,��ϵ�绰,���䣨���,QQ��,΢�ź�,��ͥסַ,"


typedef struct {
	char number[20 + 1];
	char name[10 * 2 + 1];
	char gender[1 * 2 + 1];
	char phone[20 + 1];
	char email[20 + 1];
	char qq_id[20 + 1];
	char wechat_id[20 + 1];
	char address[200];
} Student;

typedef struct
{
	Student students[100];
	int num_student;
} StudentArray;

typedef struct
{
	char source_contact_file[200];
	char target_contact_file[200];
} Filename;


void initial_filename(Filename *p)
{
	char source_file[] = "D:/study/teaching/2020�� C����-��ѧԺ19��/contacts.csv";
	char target_file[] = "D:/study/teaching/2020�� C����-��ѧԺ19��/target.csv";
	strcpy(p->source_contact_file, source_file);
	strcpy(p->target_contact_file, target_file);
}

void split(char *src, const char *separator, char **dest, int *num) 
{
	/*
	src Դ�ַ������׵�ַ(buf�ĵ�ַ)
	separator ָ���ķָ��ַ�
	dest �������ַ���������
	num �ָ�����ַ����ĸ���
	*/
	char *pNext;
	int count = 0;
	if (src == NULL || strlen(src) == 0) //�������ĵ�ַΪ�ջ򳤶�Ϊ0��ֱ����ֹ 
		return;
	if (separator == NULL || strlen(separator) == 0) //��δָ���ָ���ַ�����ֱ����ֹ 
		return;
	pNext = (char *)strtok(src, separator); //����ʹ��(char *)����ǿ������ת��(��Ȼ��д�еı������в������ָ�����)
	while (pNext != NULL) {
		*dest++ = pNext;
		++count;
		pNext = (char *)strtok(NULL, separator);  //����ʹ��(char *)����ǿ������ת��
	}
	*num = count;
}

StudentArray* read_students(char *filename)
{
	FILE *fp = 0;
	if ((fp = fopen(filename, "r")) == 0)
	{
		printf("file not found: %s\n", filename);
		return 0;
	}

	StudentArray *pArray = new StudentArray;
	memset(pArray, 0, sizeof(StudentArray));

	int counter = 0;
	char buffer[1024] = {0};
	fgets(buffer, 1024, fp);	// skip first line

	while (!feof(fp))
	{
		// read lines and parse
		Student *pStudent = pArray->students + counter;

		char *revbuf[9] = { 0 };
		int num = 0;
		fgets(buffer, 1024, fp);

		split(buffer, ",", revbuf, &num); //���ú������зָ�
		if (num == 9)
		{
			strcpy(pStudent->number, revbuf[0]);
			strcpy(pStudent->name, revbuf[1]);
			strcpy(pStudent->gender, revbuf[2]);
			strcpy(pStudent->phone, revbuf[3]);
			strcpy(pStudent->email, revbuf[4]);
			strcpy(pStudent->qq_id, revbuf[5]);
			strcpy(pStudent->wechat_id, revbuf[6]);
			strcpy(pStudent->address, revbuf[7]);
			counter++;
		}
		
	}
	pArray->num_student = counter;

	return pArray;
}

void print_students(StudentArray* pArray)
{
	if (pArray->num_student <= 0)
	{
		printf("No student information.\n");
		return;
	}
	for (int i = 0; i < pArray->num_student; i++)
	{
		Student *pStudent = pArray->students + i;
		printf("%s,%s,%s,%s,%s,%s,%s,%s\n", pStudent->number,
			pStudent->name, pStudent->gender, pStudent->phone, pStudent->email,
			pStudent->qq_id, pStudent->wechat_id, pStudent->address);
	}
}