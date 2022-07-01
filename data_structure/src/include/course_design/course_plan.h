#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

#include"../Graph.h"

void split(char* src, const char* separator, char** dest, int* num)
{
	/*
	src Դ�ַ������׵�ַ(buf�ĵ�ַ)
	separator ָ���ķָ��ַ�
	dest �������ַ���������
	num �ָ�����ַ����ĸ���
	*/
	char* pNext;
	int count = 0;
	if (src == NULL || strlen(src) == 0) //�������ĵ�ַΪ�ջ򳤶�Ϊ0��ֱ����ֹ 
		return;
	if (separator == NULL || strlen(separator) == 0) //��δָ���ָ���ַ�����ֱ����ֹ 
		return;
	pNext = (char*)strtok(src, separator); //����ʹ��(char *)����ǿ������ת��(��Ȼ��д�еı������в������ָ�����)
	while (pNext != NULL) {
		*dest++ = pNext;
		++count;
		pNext = (char*)strtok(NULL, separator);  //����ʹ��(char *)����ǿ������ת��
	}
	*num = count;
}


void get_weights(char *filename, Edge *edges, int &n)
{
	FILE* fp = 0;
	if ((fp = fopen(filename, "r")) == 0)
	{
		printf("file not found: %s\n", filename);
	}
	char buffer[1024] = { 0 };
	int counter = 0;

	while (!feof(fp))
	{
		// read lines and parse

		char* revbuf[7] = { 0 };
		int num = 0;
		fgets(buffer, 1024, fp);

		split(buffer, " ", revbuf, &num); // ���ú������зָ�
		if (num == 2)
		{
			int from = atoi(revbuf[0]);
			int to = atoi(revbuf[1]);
			edges[counter].u = from;
			edges[counter].v = to;
			counter++;
		}
	}
	n = counter;
}


void program_entry()
{
	char course_topology_file[256] = "E:/workspace/vs_course/data_structure/src/include/course_design/course_topology.txt";

	Edge edges[20];
	int edge_number = 0;
	get_weights(course_topology_file, edges, edge_number);

}
