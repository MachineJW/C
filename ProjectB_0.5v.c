/*��ó�� ������*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h> // time()�Լ� ���� ���̺귯��
#include <windows.h> // ������ �ܼ� â�� Ŀ�����ϱ� ���� ������� ����

void round_printer(int x);
int random_candidate (char* selecter);


/*���� ���� ����*/
char* candidate[16];// ������ ���ڿ� �迭, �޸� �ּҰ����� �迭���·ν� 2���� �迭ó�� �ٷ�� �ִ�.


/* �ܼ� â ���� ������ ���� */
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

/* �ܼ� �ؽ�Ʈ ���� �������ִ� �Լ� */
void setColor(unsigned short text) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}


/*�ѱ� txt ���ڵ� ��� : ANSI(�ƽ�Ű�ڵ��� Ȯ����)*/
int main()
{
	FILE* event; // event: ���� ���� ������ ����
	FILE* event_game; // ������ ������ txt���� ������ ����

	int ch;
	int cnt = 0 ; // ī��Ʈ �뵵
	unsigned int event_select; // ���ÿ� �ϴ�, ��ȣ�� �����Ƿ�..
	setColor(GREEN);
	printf("    ������������� \n");
	printf("    ��                    �� \n");
	printf("    �� �̻��� ������ v0.1 �� \n");
	printf("    ��                    �� \n");
	printf("    ������������� \n");
	event = fopen("event.txt", "r");
	if (event == NULL)
	{
		setColor(RED);
		printf("\a [ERROR] ���� ������ �ҷ����� ���Ͽ����ϴ�.");
		return 1;
	}
	setColor(BLUE);
	printf("\n     ������\n");
	printf("     �� ���� �� \n");
	printf("     ������ \n");
	printf("\n");

	// ���� ���

	while(1)
	{
		ch = fgetc(event);
		if (ch == EOF) break;
		else if (ch == '\n')
		{
			cnt++; // ���� ������ ī��Ʈ, ��ǥ������ ���� ���๮���� ������ �ľ���.
		}
		putchar(ch);
	}
	cnt++;// ������ ������ �ľ� �����Ƿ� while���� ���������� +1�� ���ش�
	printf("\nCNT: %d", cnt);// ���񰹼��� �� ī��Ʈ �Ǿ����� Ȯ���غ���
	fclose(event);
	// ������
select:
	setColor(WHITE);
	printf("\n\n  ���� ��ȣ�� �����ϼ���: ");
	if (scanf_s("%d", &event_select) == 0) // scanf �Լ��� �̻��� ���� ������ 0�� ��ȯ�Ѵ�.
	{
		setColor(RED);
		rewind(stdin); // ǥ�� �Է� ���ۿ� ��� ��� ���ڸ� ����
		printf(" \a[ ERROR ] : �Է��� �ٽ� Ȯ���ϼ���!");
		goto select; // ����ó�� ������ �б⹮
	}


	else if (event_select > cnt || event_select < 0)
	{
		setColor(RED);
		printf(" \a[ ERROR ] : ������ �ٽ� Ȯ���ϼ���!");
		rewind(stdin); // ǥ�� �Է� ���ۿ� ��� ��� ���ڸ� ����
		goto select; // ����ó�� ������ �б⹮
	}

	system("cls"); // �ܼ� ȭ�� Clear ������ �ý��� ��ɾ�.

	char selecter_swap [20] ;
	itoa(event_select, selecter_swap, 10); //  itoa �Լ� : int���� 10������ ǥ���Ͽ� ���ڿ��� ��´�.
	strcat(selecter_swap, ".txt"); // strcat �Լ� : �տ� �μ��� ���� ���ڿ��� ���� �μ��� ���� ���ڿ��� ���Ѵ�.
	printf("%s ������ ���ڽ��ϴ�.", selecter_swap);
	event_game = fopen(selecter_swap, "r");
	if (event_game == NULL)
	{
		setColor(RED);
		printf("\a [ERROR] �ĺ� ������ �ҷ����� ���Ͽ����ϴ�.");
		goto select;
	}


	setColor(BLUE);
	printf("\n     ������\n");
	printf("     �� �ĺ� �� \n");
	printf("     ������ \n");
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
	return 0;
}


void round_printer(int x)
{
	setColor(DARK_GREEN);
	printf("     ������ \n");
	printf("     �� %2d�� �� \n",x);
	printf("     ������ \n");
	printf("\n");
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
		printf("\a [ERROR] �ĺ� ������ �ҷ����� ���Ͽ����ϴ�.");
		return 1;
	}

	srand(time(NULL)); // ���� �Լ� �ʱ�ȭ

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
				// �� ������ �ٽ� ���ΰ� �ʿ�
				len = strlen(buffer) + 1;
				candidate[i] = (char*)malloc(sizeof(char) * len);
				strcpy(candidate[i], buffer);
				// �������, �ٽ� �����ؾ���
				printf("cand[%d] : %s", i ,candidate[i]);
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