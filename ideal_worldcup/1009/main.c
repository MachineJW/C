/*전처리 지시자*/
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
	system("mode con cols=60 lines=35"); // 콘솔창 크기
main:
	selection = main_menu();
	if (selection == -1) return -1;
	cus = user_custom(selection);
	if (cus.round == -1) goto main; // round.user가 -1이 반환값이라면 파일 오류..
	char* cand = (char*)malloc(sizeof(char) * cus.round);
	random_candidate(*cand , cus.file_txt, cus.round);

	return 0;
}