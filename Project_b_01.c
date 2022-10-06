#include <stdio.h>
/*한글 txt 인코딩 방식 : ANSI(아스키코드의 확장판)*/
int main()
{
	FILE* event; // event: 종목 파일 포인터 변수
	int ch;
	int i,j = 0;
	int cnt = 0 ; // 카운트 용도
	unsigned int event_select; // 선택용 일단, 부호가 없으므로..
	/*포인터 배열은 2차원 배열 처럼 사용할수 있다*/
	char* select_ary[50]; // 문자열을 담을 포인터 배열 선언
	char str[10]; // 문자를 담을 배열 선언

	printf("\n[ 이상형 월드컵 ]\n");
	event = fopen("event.txt", "r");
	if (event == NULL)
	{
		printf("종목 파일을 불러오지 못하였습니다.");
		return 1;
	}
	printf("[ 종목 ]\n");

	// 종목 출력

	while(1)
	{
		str[i] = fgetc(event);
		if (str[i] == EOF) break;
		else if (str[i] == '\n')
		{
			for (j = 0; j <= i; j++) select_ary[cnt] = str[j];
			i = 0;
			cnt++; // 종목 갯수를 카운트, 대표적으로 엔터 개행문자의 갯수를 파악함.
		}
	}


	cnt++;//while문을 빠져나오면 +1을 해준다. 엔터의 갯수를 파악 했으므로
	printf("\nCNT: %d", cnt); // 종목갯수가 잘 카운트 되었는지 확인해본다
	
	// 종목선택
select:

	printf("\n종목 번호를 선택하세요: ");
	if (scanf_s("%d", &event_select) == 0) // scanf 함수는 이상한 값이 들어오면 0을 반환한다.
	{
		rewind(stdin); // 표준 입력 버퍼에 담긴 모든 문자를 제거
		printf("경고 : 입력을 다시 확인하세요!");
		goto select; // 예외처리 무조건 분기문
	}


	else if (event_select > cnt || event_select < 0)
	{
		printf("경고 : 범위를 다시 확인하세요!");
		rewind(stdin); // 표준 입력 버퍼에 담긴 모든 문자를 제거
		goto select; // 예외처리 무조건 분기문
	}


	while (1)
	{
		ch = fgetc(event);
		if (ch == EOF)
		{
			break;
		}
		putchar(ch);
	}


	if (fclose(event)== 0)
	{
		printf("\n파일을 완벽하게 닫았습니다");
	}
	return 0;
}