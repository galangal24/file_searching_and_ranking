// circular_list_exercise.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>


//about struct listnode : resource from : http://robodream.tistory.com/173

int get_num_of_let(char *let, FILE *fp);
void store_cnt(int cnt);

int main()
{
	//resource from http://www.pmguda.com/408
	WIN32_FIND_DATA FindData;
	HANDLE hFind;
	FILE *fp=NULL;
	char txt[500];
	int i = 1, cnt = 0;
	char let[20];
	//char line[5000] = {};
	//�ܾ� �Է��ϱ�
	
	printf("input letter you want to search :");
	fgets(let, 20, stdin);
	//printf(" %s\n", let);
	
	strcpy(txt, "C:\\Users\\USER\\Desktop\\dataset\\dataset\\*");
	//strcpy(txt, "C:\\>mysearch hello\\*");
	hFind = FindFirstFile((LPCSTR)txt, &FindData);
	if (hFind == INVALID_HANDLE_VALUE) {
		return 0;
	}
	do {
		//���⿡�� ������ �ϳ��� ã�� �Ϳ� ���� �ܾ � �ִ��� �˻��ؾߵ�
		//ã�� �ܾ��� ������ ���° ���������� 
		printf("%d : %s\n", i, FindData.cFileName);//���� �̸��� ��ȣ ���
		//fp = fopen(FindData.cFileName, "r");//���� ����
		//���� �� Ư�� �ܾ��� ����
		/*
		while (!feof(fp)) {
			fscanf(fp, "%s", line);
			if (line == let) cnt++;
		}
		store_cnt(cnt);*/
		i++;
	} while (FindNextFile(hFind, &FindData));

	FindClose(hFind);
	system("pause");

    return 0;
}

int get_num_of_let(char *let, FILE *fp) {
	char line[5000];
	int cnt = 0;
	while (!feof(fp)) {
		fgets(line, 5000, fp);
		if (strstr(line, let) != NULL) {
			cnt++;
		}
	}
	return cnt;
}
void store_cnt(int cnt) {
	char num[1] = { cnt };
	FILE *fp;
	fp = fopen("store.txt", "a");
	fputs(num, fp);
	fputs("\n", fp);
	fclose(fp);
}

