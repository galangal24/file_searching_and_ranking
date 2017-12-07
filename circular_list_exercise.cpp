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
	//단어 입력하기
	
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
		//여기에서 파일을 하나씩 찾은 것에 대해 단어가 몇개 있는지 검색해야됨
		//찾은 단어의 갯수와 몇번째 파일인지를 
		printf("%d : %s\n", i, FindData.cFileName);//파일 이름과 번호 출력
		//fp = fopen(FindData.cFileName, "r");//파일 열기
		//파일 내 특정 단어의 개수
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

