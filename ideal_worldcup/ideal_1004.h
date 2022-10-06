/*����ü*/
// ����ڰ� �����ϴ� �����͸� ���� ����� ���� �ڷ���
typedef struct {
	char file_txt[100];
	int round;
} Custom;


/*������*/
// SetColor �Լ��� �μ��� ���� ������ ����
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

/*�Լ�����*/
int ch_max(FILE* TXT); // ���� ���� ���� �ִ� ���� �ľ��Ͽ� ���� ��
void line_printer(int max); // �Ű������� �� �� ��ŭ ������ �������
Custom user_custom(int select_num); // ������� ���� (������ ����, �� �� ����, �ؽ�Ʈ������ �迭 �ּҰ�)
char* select_txt(int select_num); // ������ ��ȣ�� ������, txt���·� ��ȯ���ش�.
int round_find (int cand_cnt); // �ĺ� ������ ������ �ĺ����� ������ ���� ����� ���带 ��ȯ�Ѵ�.


void setColor(Color text) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}

/*���θ޴�*/
int main_menu(void) {
	FILE* event; // ���� ����ü ������
	int ch; // txt ���� ��ġ�����ڸ� ���� ����
	unsigned int event_cnt = 0; // ���� ������ ī��Ʈ �뵵
	unsigned int max_cnt = 0;
	unsigned int event_select;
	unsigned int cnt = 0;
	unsigned int event_add = 0 ,cand_add = 0;


	system("cls");
	PlaySound(TEXT("main.wav"), NULL, SND_FILENAME | SND_ASYNC);
	setColor(DAKR_YELLOW);
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

	setColor(YELLOW);
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
			event_cnt++; // ���� ������ ī��Ʈ, ���� ���๮���� ������ �ľ���.
		}
		putchar(ch);
	}
	event_cnt++;// ������ ������ �ľ� �����Ƿ� while���� ���������� +1�� ���ش�	
	event_add = (event_cnt + 1);
	cand_add = (event_cnt + 2);
	printf("\n");
	line_printer(max_cnt);
	printf("\n[%d] ���� �߰�\n", event_add );
	line_printer(max_cnt);
	printf("\n[%d] �ĺ� �߰�\n", cand_add );
	line_printer(max_cnt);
	fclose(event);

	// ������
select:
	setColor(WHITE);
	printf("\n ��ȣ�� �����ϼ���: ");
	if (scanf_s("%d", &event_select) == 0) // scanf �Լ��� �̻��� ���� ������ 0�� ��ȯ�Ѵ�.
	{
		setColor(RED);
		rewind(stdin); // ǥ�� �Է� ���ۿ� ��� ��� ���ڸ� ����
		printf(" \a[ ERROR ] : �Է��� �ٽ� Ȯ���ϼ���!");
		goto select; // ����ó�� ������ �б⹮
	}

	else if (event_select > cand_add || event_select < 0)
	{
		setColor(RED);
		printf(" \a[ ERROR ] : ������ �ٽ� Ȯ���ϼ���!");
		rewind(stdin); // ǥ�� �Է� ���ۿ� ��� ��� ���ڸ� ����
		goto select; // ����ó�� ������ �б⹮
	}

	return event_select;
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
	for (int i = 0; i < max; i++) printf("��");
}

Custom user_custom(int select_num ) // user.round�� -1��ȯ�̸� ����
{
	int ch;// ���� ��ġ�����ڸ� ���� ����
	int cnt = 0;
	int round_max = 0; // round�� �ִ밪�� ���� ����

	FILE* select_event;
	Custom user; // ����ü ���� user
	Custom* p_user = &user; // ����ü user ������
	setColor(DARK_GREEN);
	system("cls");
	PlaySound(TEXT("main.wav"), NULL, SND_FILENAME | SND_ASYNC);
	strcpy((p_user->file_txt), select_txt(select_num));
	printf("��������������������������������������������������������������������������������������\n");
	printf("   �� %s ������ ���ڽ��ϴ�. �� \n", (p_user->file_txt));
	printf("��������������������������������������������������������������������������������������\n");
	Sleep(500);
	select_event = fopen(user.file_txt, "r");
	if (select_event == NULL)
	{
		setColor(RED);
		printf("��������������������������������������������������������������������������������������\n");
		printf("\a[ERROR] %s ������ �ҷ����� ���Ͽ����ϴ�.\n", user.file_txt);
		printf("��������������������������������������������������������������������������������������\n");
		user.round = -1;
		Sleep(3000);
		return user;
	}
	while (1)
	{
		ch = fgetc(select_event);
		if (ch == ';') break; //�ĺ������� �������ĺ��� ���� ;�� ǥ���ϱ�� ���.
		else if (ch == EOF)
		{	
			fclose(select_event);
			setColor(RED);
			printf("������������������������������������������������������������������������������������������\n");
			printf("\a[ERROR] ; �����ڰ� �����ϴ�. �ĺ����� ����\n");
			printf("������������������������������������������������������������������������������������������\n");
			user.round = -1;
			Sleep(3000);
			return user;
		}
		else if (ch == '\n') cnt++; // �ĺ� ������ ī��Ʈ
	}
	cnt++;
	fclose(select_event); // ���� �ݱ�.
	setColor(SKYBLUE);
	printf("��������������������������������������������������������������������������������������\n");
	printf("   �� %3d���� �ĺ��� Ž���Ͽ����ϴ�. \n", cnt);
	printf("��������������������������������������������������������������������������������������\n");
	round_max = round_find(cnt);
	if (round_max == -1)
	{
		setColor(RED);
		printf("������������������������������������������������������������������������������������������\n");
		printf("\a[ERROR] �ĺ��� 2�� �̸��� �߸� �� �ĺ� ���� \n");
		printf("������������������������������������������������������������������������������������������\n");
		user.round = -1;
		Sleep(3000);
		return user;
	}
	printf("   %3d �� ���� ���� ���� �� �� �ֽ��ϴ�. \n", round_max);

}

char* select_txt(int select_num)
{
	char buffer[100];
	itoa(select_num, buffer, 10); //  itoa �Լ� : int���� 10������ ǥ���Ͽ� ���ڿ��� ��´�.
	strcat(buffer, ".txt"); // strcat �Լ� : �տ� �μ��� ���� ���ڿ��� ���� �μ��� ���� ���ڿ��� ���Ѵ�.
	return buffer;
}

int round_find(int cand_cnt)
{
	if (cand_cnt <= 1) return -1;
	int x = 2;
	while (1) 
	{
		if (x < cand_cnt) x *= 2; // 2�� �ŵ������� �μ����� ������ ��� 2�� ����
		else if (x == cand_cnt) break; // 2�� �ŵ������� �μ��� ������ �ٷ� �극��ũ
		else if (x > cand_cnt) { x /= 2; break;} // 2�� �ŵ������� �μ����� ũ�� 2�� ������ �극��ũ
	}
	return x;
}