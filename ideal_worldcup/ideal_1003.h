/*�Լ�����*/
int ch_max(FILE* TXT); // ���� ���� ���� �ִ� ���� �ľ��Ͽ� ���� ��
void line_printer(int max); // �Ű������� �� �� ��ŭ ������ �������

/*����ü*/
// �����ϴ� �����͸� ���� ����� ���� �ڷ���
// �����ǿ� ���ÿ� ����
typedef struct{
	char s_event[20];
	int select_num;
	int round;
} Selection;

/*������*/
// SetColor �Լ��� �μ��� ���� ������ ����
// �����ǿ� ���ÿ� ����
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

/*���θ޴�*/
int main_menu(void) {
	FILE* event; // ���� ����ü ������
	char buffer[100];
	int ch; // txt ���� ��ġ�����ڸ� ���� ����
	unsigned int cnt = 0; // ���� ������ ī��Ʈ �뵵
	unsigned int max_cnt = 0;
	unsigned int event_select;

	system("cls");
	PlaySound(TEXT("main.wav"), NULL, SND_FILENAME | SND_ASYNC);
	setColor(VIOLET);
	printf("    ������������� \n");
	printf("    �� �̻��� ������ v1.0 �� \n");
	printf("    ������������� \n");

	event = fopen("event.txt", "r");
	if (event == NULL)
	{
		setColor(RED);
		printf("\a [ERROR] ���� ������ �ҷ����� ���Ͽ����ϴ�.");
		return -1;
	}

	setColor(BLUE);

	printf("\n    ������\n");
	printf("    �� ���� �� \n");
	printf("    ������ \n");
	printf("\n");

	/*���� ��� ������ �ִ� ���ڼ� �ľ�*/
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
			cnt++; // ���� ������ ī��Ʈ, ���� ���๮���� ������ �ľ���.
		}
		putchar(ch);
	}

	printf("\n");
	line_printer(max_cnt);
	cnt++;// ������ ������ �ľ� �����Ƿ� while���� ���������� +1�� ���ش�

	printf("\n�ִ� ���� : %d", max_cnt);
	
	
	fclose(event);

	// ������
select:
	setColor(WHITE);
	printf("\n���� ��ȣ�� �����ϼ���: ");
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

	return 0;
}

int ch_max(FILE* TXT) 
{
	int ch; // txt ���� ��ġ�����ڸ� ���� ����
	unsigned int ch_cnt = 0, max = 0; // ������ ������ ī��Ʈ�� ����, �ִ��� ����

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
		printf("��");
	}
}