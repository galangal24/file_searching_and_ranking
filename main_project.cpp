// for_exercise.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>

int maxnum;


int cnt_let(char roaad[1000], char let[20]);
void make_ranking(char roaad[1000], int cnt);
void clearfile();


//C:\\Users\\USER\\Desktop\\dataset-2nd\\dataset-2nd\\*.txt
//strcpy(txt, "C:\\Users\\USER\\Desktop\\dataset-2nd\\dataset-2nd\\*.txt");

int main()
{
	WIN32_FIND_DATA FindData;
	HANDLE hFind;
	FILE *fp = NULL, *fpnt = NULL;
	char txt[500], tx[500], road[500], roaad[1000];
	char let[20], textname[5000], number[100];
	int i = 1, num;
	char c;

	maxnum = 0;

	printf("input letter you want to search :");
	fgets(let, 20, stdin);
	printf("input the address of the text files :");
	fgets(txt, 500, stdin);
	strcpy(tx, txt);
	strcat(txt, "*.txt");
	
	hFind = FindFirstFile((LPCSTR)txt, &FindData);
	if (hFind == INVALID_HANDLE_VALUE) {
		return 0;
	}
	do {
		printf("%d : %s\n", i, FindData.cFileName);

		
		strcpy(road, FindData.cFileName);
		strcpy(roaad, tx);
		strcat(roaad, road);
		
		num = cnt_let(roaad, let);

		make_ranking(roaad, num);

		if (maxnum < num)maxnum = num;


		i++;

	} while (FindNextFile(hFind, &FindData));

	
	FindClose(hFind);

	printf("\nThe Rank of Text Files Upon the word %s\n", let);

	i = maxnum;

	for (i; i >= 0; i--) {
		itoa(i, number, 10);
		strcat(number, ".txt");
		fpnt = fopen(number, "r");
		if (fpnt == NULL) {
			continue;
		}
		else {
			fgets(textname, sizeof(textname), fpnt);
			printf("\n------\nTextFiles with %d many numbers\n------\n", i);
			printf("%s", textname);
		}
		fclose(fpnt);
	}

	printf("\nEnd of Rank\n");
	printf("Initializing the ranking files\n");
	clearfile();


	system("pause");

    return 0;
}



int cnt_let(char roaad[1000], char let[20]) {
	FILE *fp = NULL;
	int cnt = 0;
	char c, complet[50], line[50000], *toc = NULL;
	char blk[] = " ,\t\n";
	fp = fopen(roaad, "r");
	while (1) {
		c = fgetc(fp);
		if (feof(fp)) break;
		fgets(line, 50000, fp);
		toc = strtok(line, blk);
		while (toc != NULL) {
			if (toc == let) cnt++;
			toc = (NULL, blk);
			}
		}
	fclose(fp);
	return cnt;
}

void make_ranking(char roaad[1000], int cnt) {
	FILE *fp = NULL;

	strcat(roaad, "\n");
	char num[100];
	itoa(cnt, num, 10);
	strcat(num, ".txt");
	fp = fopen(num, "a+");

	fclose(fp);
}

void clearfile() {
	FILE *fp = NULL;
	char num[100];
	int i = maxnum;
	for (i; i >= 0; i--) {
		itoa(i, num, 10);
		strcat(num, ".txt");
		fp = fopen(num, "w");
		fputs("", fp);
		fclose(fp);
	}

}


