/*��ó�� ������*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <mmsystem.h> 
#include "ideal.h"
#pragma comment (lib, "winmm.lib")

int main() {
	Custom cus;
	int selection;
	system("mode con cols=60 lines=35"); // �ܼ�â ũ��
main:
	selection = main_menu();
	if (selection == -1) return -1;
	cus = user_custom(selection);
	if (cus.round == -1) goto main; // round.user�� -1�� ��ȯ���̶�� ���� ����..
	char** cand = (char*)malloc(sizeof(char) * cus.round); // 2���� ���ڹ迭�� ���� �迭 ����
	cand = random_candidate(cus.file_txt, cus.round, cus.cand_cnt); // 2���� ���ڹ迭
	for (int i = 0; i < cus.round; i++)
	{
		printf("cand[%d] = %s\n", i, cand[i]);
	}

	return 0;
}