/*함수선언*/
int ch_max(FILE* TXT); // 파일 글자 수의 최대 값을 파악하여 리턴 함
void line_printer(int max); // 매개변수로 들어간 수 만큼 라인을 만들어줌

/*구조체*/
// 선택하는 데이터를 담을 사용자 정의 자료형
// 재정의와 동시에 선언
typedef struct{
	char s_event[20];
	int select_num;
	int round;
} Selection;

/*열거형*/
// SetColor 함수에 인수로 들어가는 열거형 정의
// 재정의와 동시에 선언
typedef enum{
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
} Color;

void setColor(Color text) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}

/*메인메뉴*/
int main_menu(void) {
	FILE* event; // 파일 구조체 포인터
	char buffer[100];
	int ch; // txt 파일 위치지시자를 담을 변수
	unsigned int cnt = 0; // 종목 갯수의 카운트 용도
	unsigned int max_cnt = 0;
	unsigned int event_select;

	system("cls");
	PlaySound(TEXT("main.wav"), NULL, SND_FILENAME | SND_ASYNC);
	setColor(VIOLET);
	printf("    ■■■■■■■■■■■■ \n");
	printf("    ■ 이상형 월드컵 v1.0 ■ \n");
	printf("    ■■■■■■■■■■■■ \n");

	event = fopen("event.txt", "r");
	if (event == NULL)
	{
		setColor(RED);
		printf("\a [ERROR] 종목 파일을 불러오지 못하였습니다.");
		return -1;
	}

	setColor(BLUE);

	printf("\n    ■■■■■\n");
	printf("    ■ 종목 ■ \n");
	printf("    ■■■■■ \n");
	printf("\n");

	/*파일 출력 글자의 최대 글자수 파악*/
	max_cnt = ch_max(event);
	max_cnt++;

	line_printer(max_cnt);
	printf("\n");

	while (1)
	{
		ch = fgetc(event);
		if (ch == EOF) break;
		else if (ch == '\n')
		{
			printf("\n");
			line_printer(max_cnt);
			cnt++; // 종목 갯수를 카운트, 엔터 개행문자의 갯수를 파악함.
		}
		putchar(ch);
	}

	printf("\n");
	line_printer(max_cnt);
	cnt++;// 엔터의 갯수를 파악 했으므로 while문을 빠져나오면 +1을 해준다

	printf("\n최대 글자 : %d", max_cnt);
	
	
	fclose(event);

	// 종목선택
select:
	setColor(WHITE);
	printf("\n종목 번호를 선택하세요: ");
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

	return 0;
}

int ch_max(FILE* TXT) 
{
	int ch; // txt 파일 위치지시자를 담을 변수
	unsigned int ch_cnt = 0, max = 0; // 글자의 갯수를 카운트할 변수, 최댓값을 저장

	while (1)
	{
		ch = fgetc(TXT);
		if (ch == EOF) break;
		else if (ch == '\n') ch_cnt = 0;
		ch_cnt++;
		if (ch_cnt > max) max = ch_cnt;
	}
	rewind(TXT);
	return max;
}

void line_printer(int max)
{
	for (int i = 0; i < max; i++)
	{
		printf("─");
	}
}