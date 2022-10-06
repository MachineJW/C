/*��ó�� ������*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h> // time()�Լ� ���� ���̺귯��
#include <windows.h> // ������ �ܼ� â�� Ŀ�����ϱ� ���� ������� ����
#include <mmsystem.h> // playsound �Լ� ����� �ϱ����� �������
#pragma comment (lib, "winmm.lib") // pragma ��ó�� ������. ������ ����� �ٲܶ� ����.


void main_printer();
void round_printer(int x );
int winner_printer();
int random_candidate (char* selecter);
int round_game(int round);


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

int main()
{
	system("mode con cols=60 lines=35"); // �ܼ�â ũ��

main:
	main_printer();
	
	int set_round = 16;
	while ( set_round != 1 )
	{
		round_game(set_round);
		set_round /= 2;
	}

	if (winner_printer() == 0) goto main;
	else
	{
		Sleep(3000);
		return 0;
	}
}


void main_printer()
{
	FILE* event; // event: ���� ���� ������ ����
	FILE* event_game; // ������ ������ txt���� ������ ����

	int ch; // txt ���� ��ġ�����ڸ� ���� ����
	int cnt = 0; // ī��Ʈ �뵵
	unsigned int event_select; // ���ÿ� �μ��� ���� ����
	
	system("cls");
	PlaySound(TEXT("main.wav"), NULL, SND_FILENAME | SND_ASYNC);
	setColor(GREEN);
	printf("    ������������� \n");
	printf("    ��                    �� \n");
	printf("    �� �̻��� ������ v0.9 �� \n");
	printf("    ��                    �� \n");
	printf("    ������������� \n");
menu:
	event = fopen("event.txt", "r");
	if (event == NULL)
	{
		setColor(RED);
		printf("\a [ERROR] ���� ������ �ҷ����� ���Ͽ����ϴ�.");
		return 1;
	}
	setColor(BLUE);

	printf("\n    ������\n");
	printf("    �� ���� �� \n");
	printf("    ������ \n");
	printf("\n");

	// ���� ���
	printf("��������������������������������\n");
	while (1)
	{
		ch = fgetc(event);
		if (ch == EOF) break;
		else if (ch == '\n')
		{
			printf("\n��������������������������������");
			cnt++; // ���� ������ ī��Ʈ, ��ǥ������ ���� ���๮���� ������ �ľ���.
		}
		putchar(ch);
	}
	printf("\n��������������������������������\n");

	cnt++;// ������ ������ �ľ� �����Ƿ� while���� ���������� +1�� ���ش�
	// printf("\nCNT: %d", cnt);// ���񰹼��� �� ī��Ʈ �Ǿ����� Ȯ���غ���
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
	PlaySound(TEXT("main.wav"), NULL, SND_FILENAME | SND_ASYNC);
	char selecter_swap[20];
	itoa(event_select, selecter_swap, 10); //  itoa �Լ� : int���� 10������ ǥ���Ͽ� ���ڿ��� ��´�.
	strcat(selecter_swap, ".txt"); // strcat �Լ� : �տ� �μ��� ���� ���ڿ��� ���� �μ��� ���� ���ڿ��� ���Ѵ�.
	printf("������������������������������������������������\n");
	printf("%s ������ ���ڽ��ϴ�.\n", selecter_swap);
	printf("������������������������������������������������\n");

	event_game = fopen(selecter_swap, "r");
	if (event_game == NULL)
	{
		setColor(RED);
		printf("\a [ERROR] �ĺ� ������ �ҷ����� ���Ͽ����ϴ�. \n");
		printf("'%s' ������ �ִ��� Ȯ�����ּ���!\n", selecter_swap );
		setColor(BLUE);
		goto menu;
	}

	setColor(BLUE);
	printf("\n     ������\n");
	printf("     �� �ĺ� �� \n");
	printf("     ������ \n");

	event = fopen("event.txt", "r");
	cnt = 0;

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

/*�ĺ� �迭 �������� �����ϱ�*/
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
				strcpy( candidate[i], buffer );
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
	printf("     ������ \n");
	printf("     �� %2d�� �� \n", x);
	printf("     ������ \n");
	printf("\n");
}

/* round_game �Լ� */
// 1. ���� ���� �μ��� ����.
// 2. ������ �����Ѵ�.
// 3. ���ڴ� ������ ������ candidate �迭�� ����. [0]vs[1]�϶� ������ �����Ͱ� ������ [0] ����....
// 4. ��, 16���� [0]vs[1],[2]vs[3],[4]vs[5]...[14]vs[15] 8���� [0]vs[2],[4]vs[6]... �̷� �������� �귯����
// 5. ���������δ� ����� [0]vs[8]�� ���°� ��

int round_game (int round )
{
	int select_vlaue = 0; // ���õǴ� ���� ���� ����
	const int set_value = (16 / round); // �񱳽Ŀ� ��� �� ���� ��
	const int in_value = ( set_value * 2 ); // �����Ŀ� ��� �� ���� ��


	for (int i = 0; i < 16 ; i += in_value )
	{
		system("cls");

		printf("[%d]\n", i );

		round_printer(round); // �� �� ���� ǥ���ϴ� �Լ� round_printer(int ���� ����)

		setColor(DARK_VOILET);
		
		printf("��������������������������������������������������������������������\n");
		printf("        [1]%s",candidate[i]);
		printf("��������������������������������������������������������������������\n");
		printf("                VS\n");
		printf("��������������������������������������������������������������������\n");
		printf("        [2]%s",candidate[(i + set_value)]);
		printf("��������������������������������������������������������������������\n\n\n");

	select:
		setColor(DAKR_YELLOW);
		printf("\n����� ������? : ");

		if (scanf_s("%d", &select_vlaue) == 0) // scanf �Լ��� �̻��� ���� ������ 0�� ��ȯ�Ѵ�.
		{
			setColor(RED);
			rewind(stdin); // ǥ�� �Է� ���ۿ� ��� ��� ���ڸ� ����
			printf(" \a[ ERROR ] : �Է��� �ٽ� Ȯ���ϼ���!");
			goto select; // ����ó�� ������ �б⹮
		}
		else if (select_vlaue > 2 || select_vlaue <= 0)
		{
			setColor(RED);
			printf(" \a[ ERROR ] : ������ �ٽ� Ȯ���ϼ���!");
			rewind(stdin); // ǥ�� �Է� ���ۿ� ��� ��� ���ڸ� ����
			goto select; // ����ó�� ������ �б⹮
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
		PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
		setColor(DARK_SKYBLUE);
		printf("     ������������� \n");
		printf("     ��      victory!!     ��\n"); 
		printf("     ������������� \n\n\n");


		printf("    �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�\n");
		printf("                %s   ", candidate[i]);
		printf(" �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�");
		Sleep(2000);
	}

	return 0;
}

int winner_printer()
{
	int select_vlaue = 0;
	system("cls");
	PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
	printf("       ����������� \n");
	printf("       ��     WINNER!!!  ��\n");
	printf("       ����������� \n\n\n");

	printf("        �������������������������������������������������������������� \n");
	printf("                  %s", candidate[0]);
	printf("        �������������������������������������������������������������� \n");

select:
	setColor(DAKR_YELLOW);
	printf("\n �ٸ� ������ �Ͻðڽ��ϱ�? ([1]:Y , [2]:N ) : ");

	if (scanf_s ("%d", &select_vlaue) == 0) 
	{
		setColor(RED);
		rewind(stdin); 
		printf(" \a[ ERROR ] : �Է��� �ٽ� Ȯ���ϼ���!");
		goto select; // ����ó�� ������ �б⹮
	}
	else if (select_vlaue > 2 || select_vlaue <= 0)
	{
		setColor(RED);
		printf(" \a[ ERROR ] : ������ �ٽ� Ȯ���ϼ���!");
		rewind(stdin);
		goto select; // ����ó�� ������ �б⹮
	}

	switch (select_vlaue)
	{
	case (1):
		return 0;
	case (2):
		PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
		printf("\n     ������\n");
		printf("     �� ���� �� \n");
		printf("     ������ \n");
		return 1;
		break;
	}
}