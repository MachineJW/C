/*구조체*/
// 사용자가 선택하는 데이터를 담을 사용자 정의 자료형
typedef struct {
	char file_txt[100];
	int round;
	int cand_cnt;
} Custom;
// 구조체 타입재정의 Custom


/*열거형*/
// SetColor 함수에 인수로 들어가는 열거형 정의
typedef enum {
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
// 열거형 타입 재정의 Color

/*함수선언*/
int ch_max(FILE* TXT); // 파일 글자 수의 최대 값을 파악하여 리턴 함
void line_printer(int max); // 매개변수로 들어간 수 만큼 라인을 만들어줌
Custom user_custom(int select_num); // 사용자의 정의 (선택한 파일, 몇 강 진행, 텍스트파일의 배열 주소값)
char* select_txt(int select_num); // 선택한 번호를 넣으면, txt형태로 반환해준다.
int round_find (int cand_cnt); // 후보 갯수를 넣으면 후보 갯수 이하의 가장 가까운 라운드를 반환한다.
int round_num(int round_max); // 최대라운드 값을 넣으면 2강 까지의 가능한 라운드 수를 반환
void round_ary(int round_max ,int* ary, int num ); // 라운드의 최대값, 배열의 주소값과 2부터 가능한 라운드 수를 계산하여 넣으면 배열에 가능한 라운드를 저장
char** random_candidate(char* file_txt, int round , int cand_cnt);  // 랜덤한 후보들을 배치! 인수로 (후보파일명, 유저가 선택한 라운드, 총 후보 갯수)

void setColor(Color text) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}

/*메인메뉴*/
int main_menu(void) {
	FILE* event; // 파일 구조체 포인터
	int ch; // txt 파일 위치지시자를 담을 변수
	unsigned int event_cnt = 0; // 종목 갯수의 카운트 용도
	unsigned int max_cnt = 0;
	unsigned int event_select;
	unsigned int cnt = 0;
	unsigned int event_add = 0 ,cand_add = 0;


	system("cls");
	PlaySound(TEXT("main.wav"), NULL, SND_FILENAME | SND_ASYNC);
	setColor(DAKR_YELLOW);
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

	setColor(YELLOW);
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
			event_cnt++; // 종목 갯수를 카운트, 엔터 개행문자의 갯수를 파악함.
		}
		putchar(ch);
	}
	event_cnt++;// 엔터의 갯수를 파악 했으므로 while문을 빠져나오면 +1을 해준다	
	event_add = (event_cnt + 1);
	cand_add = (event_cnt + 2);
	printf("\n");
	line_printer(max_cnt);
	printf("\n[%d] 종목 추가\n", event_add );
	line_printer(max_cnt);
	printf("\n[%d] 후보 추가\n", cand_add );
	line_printer(max_cnt);
	fclose(event);

	// 종목선택
select:
	setColor(WHITE);
	printf("\n 번호를 선택하세요: ");
	if (scanf_s("%d", &event_select) == 0) // scanf 함수는 이상한 값이 들어오면 0을 반환한다.
	{
		setColor(RED);
		rewind(stdin); // 표준 입력 버퍼에 담긴 모든 문자를 제거
		printf(" \a[ ERROR ] : 입력을 다시 확인하세요!");
		goto select; // 예외처리 무조건 분기문
	}

	else if (event_select > cand_add || event_select < 0)
	{
		setColor(RED);
		printf(" \a[ ERROR ] : 범위를 다시 확인하세요!");
		rewind(stdin); // 표준 입력 버퍼에 담긴 모든 문자를 제거
		goto select; // 예외처리 무조건 분기문
	}
	return event_select;
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
	for (int i = 0; i < max; i++) printf("─");
}

Custom user_custom(int select_num ) // user.round가 -1반환이면 오류
{
	int ch;// 파일 위치지시자를 담을 변수
	int cnt = 0;
	int round_max = 0; // round의 최대값을 담을 변수

	FILE* select_event;
	Custom user; // 구조체 변수 user
	Custom* p_user = &user; // 구조체 user 포인터
	setColor(DARK_GREEN);
	system("cls");
	PlaySound(TEXT("main.wav"), NULL, SND_FILENAME | SND_ASYNC);
	strcpy((p_user->file_txt), select_txt(select_num));
	printf("───────────────────────────────────────────\n");
	printf("   ※ %s 파일을 열겠습니다. ※ \n", (p_user->file_txt));
	printf("───────────────────────────────────────────\n");
	Sleep(500);
	select_event = fopen(user.file_txt, "r");
	if (select_event == NULL)
	{
		setColor(RED);
		printf("───────────────────────────────────────────\n");
		printf("\a[ERROR] %s 파일을 불러오지 못하였습니다.\n", user.file_txt);
		printf("───────────────────────────────────────────\n");
		user.round = -1; // -1 오류값 반환
		Sleep(3000);
		return user;
	}
	while (1)
	{
		ch = fgetc(select_event);
		if (ch == ';') break; //후보파일의 마지막후보는 끝에 ;를 표시하기로 약속.
		else if (ch == EOF)
		{	
			fclose(select_event);
			setColor(RED);
			printf("─────────────────────────────────────────────\n");
			printf("\a[ERROR] ; 지시자가 없습니다. 후보파일 에러\n");
			printf("─────────────────────────────────────────────\n");
			user.round = -1; // -1 오류값 반환
			Sleep(3000);
			return user;
		}
		else if (ch == '\n') cnt++; // 후보 갯수를 카운트
	}
	cnt++;
	fclose(select_event); // 파일 닫기.
	setColor(SKYBLUE);
	printf("───────────────────────────────────────────\n");
	printf("   총 %3d개의 후보를 탐색하였습니다.\n", cnt);
	printf("───────────────────────────────────────────\n");
	user.cand_cnt = cnt;
	round_max = round_find(cnt);
	if (round_max == -1)
	{
		setColor(RED);
		printf("─────────────────────────────────────────────\n");
		printf("\a[ERROR] 후보가 2개 미만의 잘못 된 후보 파일 \n");
		printf("─────────────────────────────────────────────\n");
		user.round = -1;
		Sleep(3000);
		return user;
	}
select:
	setColor(WHITE);
	printf("─────────────────────────────────────────────");
	printf("\n%3d강 이하 부터 시작 할 수 있습니다.\n", round_max);
	printf("─────────────────────────────────────────────\n");
	int num = round_num(round_max);
	int* ary = (int*)malloc(sizeof(int) * num);
	round_ary(round_max, ary, num);
	printf("\n 몇 강을 진행하시겠습니까? : ");

	int round_tmp = 0;

	if (scanf_s("%d", &round_tmp) == 0)
	{
		setColor(RED);
		rewind(stdin); // 표준 입력 버퍼에 담긴 모든 문자를 제거
		printf("\a [ ERROR ] : 입력을 다시 확인하세요!\n");
		goto select; // 예외처리 무조건 분기문
	}
	
	if (round_tmp >= num || round_tmp < 0)
	{
		setColor(RED);
		rewind(stdin); // 표준 입력 버퍼에 담긴 모든 문자를 제거
		printf("\a [ ERROR ] : 가능한 숫자를 입력하세요!\n");
		goto select;
	}

	setColor(YELLOW);
	user.round = ary[round_tmp];

	PlaySound(TEXT("main.wav"), NULL, SND_FILENAME | SND_ASYNC);
	printf("\n─────────────────────────────────────────────\n");
	printf("\n %3d강을 선택하셨습니다.\n", user.round);
	printf("\n─────────────────────────────────────────────\n");
	Sleep(3000);

	return user;
}

char* select_txt(int select_num)
{
	char buffer[100];
	itoa(select_num, buffer, 10); //  itoa 함수 : int형을 10진수로 표현하여 문자열로 담는다.
	strcat(buffer, ".txt"); // strcat 함수 : 앞에 인수로 받은 문자열에 뒤의 인수로 받은 문자열을 더한다.
	return buffer;
}

int round_find(int cand_cnt)
{
	if (cand_cnt <= 1) return -1;
	int x = 2;
	while (1) 
	{
		if (x < cand_cnt) x *= 2; // 2의 거듭제곱이 인수보다 작으면 계속 2를 곱함
		else if (x == cand_cnt) break; // 2의 거듭제곱이 인수와 같으면 바로 브레이크
		else if (x > cand_cnt) { x /= 2; break;} // 2의 거듭제곱이 인수보다 크면 2로 나눈뒤 브레이크
	}
	return x;
}

int round_num(int round_max)
{
	int cnt = 0; // 카운트 용도
	while (round_max > 1)
	{
		if (round_max == 2) {cnt++; break;}
		round_max /= 2;
		cnt++;
	}
	return cnt;
}


void round_ary(int round_max , int* ary, int num)
{
	printf("─────────────────────────────────────────────\n");
	for (int i = 0; i < num; i++)
	{
		ary[i] = round_max;
		printf("[%d]:%3d강 | %3d강으로 진행! \n", i, ary[i], ary[i]);
		if(i < (num-1)) printf("─────────────────────────────────────────────\n");
		round_max /= 2;
	}
	printf("─────────────────────────────────────────────\n");
}

/*후보 배열 랜덤으로 정렬하기*/
char** random_candidate(char* file_txt, int round, int cand_cnt)
{
	system("cls");
	printf("후보를 선정하여 무작위로 배치 합니다.\n");
	FILE* random_txt;// 후보 파일 FILE 구조체 변수 선언
	char* buffer = (char*)malloc(sizeof(char) * 100 ); // 문자열 한줄을 읽을 버퍼의 동적할당
	char** candidate = (char*)malloc(sizeof(char) * round); //문자열 주소값들의 배열의 동적할당 (즉, 2차원 문자열 배열...)
	int* rand_ary = (int*)malloc(sizeof(int) * cand_cnt); // 랜덤한 숫자값을 담을 배열

	random_txt = fopen(file_txt, "r");
	if (random_txt == NULL)
	{
		setColor(RED);
		printf("─────────────────────────────────────────────\n");
		printf("\a [ERROR] 후보 파일을 불러오지 못하였습니다.");
		printf("─────────────────────────────────────────────\n");
		return;
	}

	srand(time(NULL)); // 랜덤 함수 초기화


	for (int i = 0; i < cand_cnt; i++)
	{
		rand_ary[i] = rand() % cand_cnt;
		for (int j = 0; j < i; j++)
		{
			if (rand_ary[i] == rand_ary[j]) i--;
		}
	}

	int cnt = 0;
	int len = 0;

	for (int i = 0; i < round; i++)
	{
		while (1)
		{
			fgets(buffer, 100, random_txt);
			if (cnt == rand_ary[i]) {
				len = strlen(buffer) + 1;
				candidate[i] = (char*)malloc(sizeof(char) * len);
				strcpy(candidate[i], buffer);

				/*";"문자 제거하기*/
				if (strstr(buffer,";") != NULL)
				{
					rewind(buffer);
					for (; *buffer != '\n'; buffer++) //종료 문자를 만날 때까지 반복
					{
						if (*buffer == ";")//ch와 같은 문자일 때
						{
							strcpy(buffer, buffer + 1);
							buffer--;
						}
					}
					strcpy(candidate[i], buffer);
				}
				break;
			}
			cnt++;
		}
		cnt = 0;
		rewind(random_txt);
	}
	fclose(random_txt);

	return candidate; //2차원 문자 배열....
}
