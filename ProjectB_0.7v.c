/*전처리 지시자*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h> // time()함수 포함 라이브러리
#include <windows.h> // 윈도우 콘솔 창을 커스텀하기 위한 헤더파일 선언


void main_printer();
void round_printer(int x );
int winner_printer();
int random_candidate (char* selecter);
int round_game(int round);


/*전역 변수 선언*/
char* candidate[16];// 포인터 문자열 배열, 메모리 주소값들의 배열형태로써 2차원 배열처럼 다룰수 있다.


/* 콘솔 창 색상 열거형 정의 */
enum {
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKYBLUE,
	DARK_RED,
	DARK_VOILET,
	DAKR_YELLOW,
	GRAY,
	DARK_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIOLET,
	YELLOW,
	WHITE,
};

/* 콘솔 텍스트 색상 변경해주는 함수 */
void setColor(unsigned short text) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}

int main()
{
  main:
	main_printer();
	
	int set_round = 16;
	while ( set_round != 1 )
	{
		round_game(set_round);
		set_round /= 2;
	}

	if (winner_printer() == 0) goto main;
	else return 0;
}


void main_printer()
{
	FILE* event; // event: 종목 파일 포인터 변수
	FILE* event_game; // 선택한 게임의 txt파일 포인터 변수

	int ch;
	int cnt = 0; // 카운트 용도
	unsigned int event_select; // 선택용 일단, 부호가 없으므로..
	
	system("cls");

	setColor(GREEN);
	printf("    ■■■■■■■■■■■■ \n");
	printf("    ■                    ■ \n");
	printf("    ■ 이상형 월드컵 v0.7 ■ \n");
	printf("    ■                    ■ \n");
	printf("    ■■■■■■■■■■■■ \n");
	event = fopen("event.txt", "r");
	if (event == NULL)
	{
		setColor(RED);
		printf("\a [ERROR] 종목 파일을 불러오지 못하였습니다.");
		return 1;
	}
	setColor(BLUE);
	printf("\n     ■■■■■\n");
	printf("     ■ 종목 ■ \n");
	printf("     ■■■■■ \n");
	printf("\n");

	// 종목 출력

	while (1)
	{
		ch = fgetc(event);
		if (ch == EOF) break;
		else if (ch == '\n')
		{
			cnt++; // 종목 갯수를 카운트, 대표적으로 엔터 개행문자의 갯수를 파악함.
		}
		putchar(ch);
	}
	cnt++;// 엔터의 갯수를 파악 했으므로 while문을 빠져나오면 +1을 해준다
	printf("\nCNT: %d", cnt);// 종목갯수가 잘 카운트 되었는지 확인해본다
	fclose(event);
	// 종목선택
select:
	setColor(WHITE);
	printf("\n\n  종목 번호를 선택하세요: ");
	if (scanf_s("%d", &event_select) == 0) // scanf 함수는 이상한 값이 들어오면 0을 반환한다.
	{
		setColor(RED);
		rewind(stdin); // 표준 입력 버퍼에 담긴 모든 문자를 제거
		printf(" \a[ ERROR ] : 입력을 다시 확인하세요!");
		goto select; // 예외처리 무조건 분기문
	}

	else if (event_select > cnt || event_select < 0)
	{
		setColor(RED);
		printf(" \a[ ERROR ] : 범위를 다시 확인하세요!");
		rewind(stdin); // 표준 입력 버퍼에 담긴 모든 문자를 제거
		goto select; // 예외처리 무조건 분기문
	}
	system("cls"); // 콘솔 화면 Clear 윈도우 시스템 명령어.

	char selecter_swap[20];
	itoa(event_select, selecter_swap, 10); //  itoa 함수 : int형을 10진수로 표현하여 문자열로 담는다.
	strcat(selecter_swap, ".txt"); // strcat 함수 : 앞에 인수로 받은 문자열에 뒤의 인수로 받은 문자열을 더한다.
	printf("%s 파일을 열겠습니다.", selecter_swap);
	event_game = fopen(selecter_swap, "r");
	if (event_game == NULL)
	{
		setColor(RED);
		printf("\a [ERROR] 후보 파일을 불러오지 못하였습니다.");
		goto select;
	}

	setColor(BLUE);
	printf("\n     ■■■■■\n");
	printf("     ■ 후보 ■ \n");
	printf("     ■■■■■ \n");
	event = fopen("event.txt", "r");
	cnt = 0;
	while (1)
	{
		ch = fgetc(event);
		if (ch == EOF) break;
		else if (ch == '\n')
		{
			cnt++;
		}
		if (cnt == event_select - 1) putchar(ch);
	}
	fclose(event);
	printf("\n");
	while (1)
	{
		ch = fgetc(event_game);
		if (ch == EOF) break;
		putchar(ch);
	}
	fclose(event_game);
	Sleep(5000);

	system("cls");

	random_candidate(selecter_swap);
}

int random_candidate(char* selecter)
{
	FILE* random_txt;
	char buffer[100];
	int len,i,j,cnt = 0;

	int rand_ary[16];

	random_txt = fopen(selecter,"r");

	if (random_txt == NULL)
	{
		setColor(RED);
		printf("\a [ERROR] 후보 파일을 불러오지 못하였습니다.");
		return 1;
	}

	srand(time(NULL)); // 랜덤 함수 초기화

	for (i = 0; i < 16; i++)
	{
		rand_ary[i] = rand() % 16;

		for (j = 0; j < i; j++) 
		{
			if (rand_ary[i] == rand_ary[j]) i--;
		}
	}

	for (i = 0; i < 16; i++)
	{
		while (1) 
		{
			fgets( buffer, 100, random_txt );
			if (cnt == rand_ary[i]) {
				// 이 과정은 다시 공부가 필요
				len = strlen(buffer) + 1;
				candidate[i] = (char*)malloc(sizeof(char) * len);
				strcpy(candidate[i], buffer);
				break;
			}
			cnt++;
		}
		cnt = 0;
		rewind(random_txt);
	}
	fclose(random_txt);
	return 0;
}

void round_printer(int x)
{
	setColor(DARK_GREEN);
	printf("     ■■■■■ \n");
	printf("     ■ %2d강 ■ \n", x);
	printf("     ■■■■■ \n");
	printf("\n");
}

/* round_game 함수 */
// 1. 라운드 값이 인수로 들어간다.
// 2. 게임을 진행한다.
// 3. 승자는 무조건 왼쪽의 candidate 배열로 들어간다. [0]vs[1]일때 승자의 데이터가 무조건 [0] 으로....
// 4. 즉, 16강은 [0]vs[1],[2]vs[3],[4]vs[5]...[14]vs[15] 8강은 [0]vs[2],[4]vs[6]... 이런 형식으로 흘러가며
// 5. 최종적으로는 결승은 [0]vs[8]의 형태가 됨

int round_game (int round )
{
	int select_vlaue = 0; // 선택되는 값을 넣을 변수
	const int set_value = (16 / round); // 비교식에 사용 될 셋팅 값
	const int in_value = ( set_value * 2 ); // 증감식에 사용 될 셋팅 값


	for (int i = 0; i < 16 ; i += in_value )
	{
		system("cls");

		printf("[%d]\n", i );

		round_printer(round); // 몇 강 인지 표기하는 함수 round_printer(int 라운드 숫자)

		setColor(DARK_VOILET);
		
		printf("■■■■■■■■■■ \n");
		printf("   [1]%s",candidate[i]);
		printf("■■■■■■■■■■ \n");
		printf("        VS\n");
		printf("■■■■■■■■■■ \n");
		printf("   [2]%s",candidate[(i + set_value)]);
		printf("■■■■■■■■■■ \n\n\n");

	select:
		setColor(DAKR_YELLOW);
		printf("\n당신의 선택은? : ");

		if (scanf_s("%d", &select_vlaue) == 0) // scanf 함수는 이상한 값이 들어오면 0을 반환한다.
		{
			setColor(RED);
			rewind(stdin); // 표준 입력 버퍼에 담긴 모든 문자를 제거
			printf(" \a[ ERROR ] : 입력을 다시 확인하세요!");
			goto select; // 예외처리 무조건 분기문
		}
		else if (select_vlaue > 2 || select_vlaue <= 0)
		{
			setColor(RED);
			printf(" \a[ ERROR ] : 범위를 다시 확인하세요!");
			rewind(stdin); // 표준 입력 버퍼에 담긴 모든 문자를 제거
			goto select; // 예외처리 무조건 분기문
		}

		switch (select_vlaue)
		{
			case (1) :
				break;
			case (2) :
				strcpy(candidate[i], candidate[(i + set_value)]);
				break;
		} 

		system("cls");
		setColor(DARK_GREEN);
		printf("■■■■■■■■■■ \n");
		printf("      victory!! \n");
		printf("■■■■■■■■■■ \n\n\n");


		printf("■■■■■■■■■■ \n");
		printf("   %s", candidate[i]);
		printf("■■■■■■■■■■ \n");

		Sleep(3000);
	}

	return 0;
}

int winner_printer()
{
	int select_vlaue = 0;

	system("cls");
	printf("■■■■■■■■■■ \n");
	printf("      WINNER!!! \n");
	printf("■■■■■■■■■■ \n\n\n");

	printf("■■■■■■■■■■ \n");
	printf("   %s", candidate[0]);
	printf("■■■■■■■■■■ \n");

select:
	setColor(DAKR_YELLOW);
	printf("\n 다른 게임을 하시겠습니까? ([1]:Y , [2]:N ) : ");

	if (scanf_s("%d", &select_vlaue) == 0) // scanf 함수는 이상한 값이 들어오면 0을 반환한다.
	{
		setColor(RED);
		rewind(stdin); // 표준 입력 버퍼에 담긴 모든 문자를 제거
		printf(" \a[ ERROR ] : 입력을 다시 확인하세요!");
		goto select; // 예외처리 무조건 분기문
	}
	else if (select_vlaue > 2 || select_vlaue <= 0)
	{
		setColor(RED);
		printf(" \a[ ERROR ] : 범위를 다시 확인하세요!");
		rewind(stdin); // 표준 입력 버퍼에 담긴 모든 문자를 제거
		goto select; // 예외처리 무조건 분기문
	}

	switch (select_vlaue)
	{
	case (1):
		return 0;
		break;
	case (2):
		printf("\n     ■■■■■\n");
		printf("     ■ 종료 ■ \n");
		printf("     ■■■■■ \n");
		return 1;
		break;
	}
}