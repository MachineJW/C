#include <stdio.h>
#include <windows.h> // ������ �ܼ� â�� Ŀ�����ϱ� ���� ������� ����

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


	setColor(DAKR_YELLOW);
}