#include <stdio.h>
/*�ѱ� txt ���ڵ� ��� : ANSI(�ƽ�Ű�ڵ��� Ȯ����)*/
int main()
{
	FILE* event; // event: ���� ���� ������ ����
	int ch;
	int i,j = 0;
	int cnt = 0 ; // ī��Ʈ �뵵
	unsigned int event_select; // ���ÿ� �ϴ�, ��ȣ�� �����Ƿ�..
	/*������ �迭�� 2���� �迭 ó�� ����Ҽ� �ִ�*/
	char* select_ary[50]; // ���ڿ��� ���� ������ �迭 ����
	char str[10]; // ���ڸ� ���� �迭 ����

	printf("\n[ �̻��� ������ ]\n");
	event = fopen("event.txt", "r");
	if (event == NULL)
	{
		printf("���� ������ �ҷ����� ���Ͽ����ϴ�.");
		return 1;
	}
	printf("[ ���� ]\n");

	// ���� ���

	while(1)
	{
		str[i] = fgetc(event);
		if (str[i] == EOF) break;
		else if (str[i] == '\n')
		{
			for (j = 0; j <= i; j++) select_ary[cnt] = str[j];
			i = 0;
			cnt++; // ���� ������ ī��Ʈ, ��ǥ������ ���� ���๮���� ������ �ľ���.
		}
	}


	cnt++;//while���� ���������� +1�� ���ش�. ������ ������ �ľ� �����Ƿ�
	printf("\nCNT: %d", cnt); // ���񰹼��� �� ī��Ʈ �Ǿ����� Ȯ���غ���
	
	// ������
select:

	printf("\n���� ��ȣ�� �����ϼ���: ");
	if (scanf_s("%d", &event_select) == 0) // scanf �Լ��� �̻��� ���� ������ 0�� ��ȯ�Ѵ�.
	{
		rewind(stdin); // ǥ�� �Է� ���ۿ� ��� ��� ���ڸ� ����
		printf("��� : �Է��� �ٽ� Ȯ���ϼ���!");
		goto select; // ����ó�� ������ �б⹮
	}


	else if (event_select > cnt || event_select < 0)
	{
		printf("��� : ������ �ٽ� Ȯ���ϼ���!");
		rewind(stdin); // ǥ�� �Է� ���ۿ� ��� ��� ���ڸ� ����
		goto select; // ����ó�� ������ �б⹮
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
		printf("\n������ �Ϻ��ϰ� �ݾҽ��ϴ�");
	}
	return 0;
}