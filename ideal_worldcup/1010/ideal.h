/*±¸Á¶Ã¼*/
// »ç¿ëÀÚ°¡ ¼±ÅÃÇÏ´Â µ¥ÀÌÅÍ¸¦ ´ãÀ» »ç¿ëÀÚ Á¤ÀÇ ÀÚ·áÇü
typedef struct {
	char file_txt[100];
	int round;
	int cand_cnt;
} Custom;
// ±¸Á¶Ã¼ Å¸ÀÔÀçÁ¤ÀÇ Custom


/*¿­°ÅÇü*/
// SetColor ÇÔ¼ö¿¡ ÀÎ¼ö·Î µé¾î°¡´Â ¿­°ÅÇü Á¤ÀÇ
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
// ¿­°ÅÇü Å¸ÀÔ ÀçÁ¤ÀÇ Color

/*ÇÔ¼ö¼±¾ð*/
int ch_max(FILE* TXT); // ÆÄÀÏ ±ÛÀÚ ¼öÀÇ ÃÖ´ë °ªÀ» ÆÄ¾ÇÇÏ¿© ¸®ÅÏ ÇÔ
void line_printer(int max); // ¸Å°³º¯¼ö·Î µé¾î°£ ¼ö ¸¸Å­ ¶óÀÎÀ» ¸¸µé¾îÁÜ
Custom user_custom(int select_num); // »ç¿ëÀÚÀÇ Á¤ÀÇ (¼±ÅÃÇÑ ÆÄÀÏ, ¸î °­ ÁøÇà, ÅØ½ºÆ®ÆÄÀÏÀÇ ¹è¿­ ÁÖ¼Ò°ª)
char* select_txt(int select_num); // ¼±ÅÃÇÑ ¹øÈ£¸¦ ³ÖÀ¸¸é, txtÇüÅÂ·Î ¹ÝÈ¯ÇØÁØ´Ù.
int round_find (int cand_cnt); // ÈÄº¸ °¹¼ö¸¦ ³ÖÀ¸¸é ÈÄº¸ °¹¼ö ÀÌÇÏÀÇ °¡Àå °¡±î¿î ¶ó¿îµå¸¦ ¹ÝÈ¯ÇÑ´Ù.
int round_num(int round_max); // ÃÖ´ë¶ó¿îµå °ªÀ» ³ÖÀ¸¸é 2°­ ±îÁöÀÇ °¡´ÉÇÑ ¶ó¿îµå ¼ö¸¦ ¹ÝÈ¯
void round_ary(int round_max ,int* ary, int num ); // ¶ó¿îµåÀÇ ÃÖ´ë°ª, ¹è¿­ÀÇ ÁÖ¼Ò°ª°ú 2ºÎÅÍ °¡´ÉÇÑ ¶ó¿îµå ¼ö¸¦ °è»êÇÏ¿© ³ÖÀ¸¸é ¹è¿­¿¡ °¡´ÉÇÑ ¶ó¿îµå¸¦ ÀúÀå
char** random_candidate(char* file_txt, int round , int cand_cnt);  // ·£´ýÇÑ ÈÄº¸µéÀ» ¹èÄ¡! ÀÎ¼ö·Î (ÈÄº¸ÆÄÀÏ¸í, À¯Àú°¡ ¼±ÅÃÇÑ ¶ó¿îµå, ÃÑ ÈÄº¸ °¹¼ö)

void setColor(Color text) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}

/*¸ÞÀÎ¸Þ´º*/
int main_menu(void) {
	FILE* event; // ÆÄÀÏ ±¸Á¶Ã¼ Æ÷ÀÎÅÍ
	int ch; // txt ÆÄÀÏ À§Ä¡Áö½ÃÀÚ¸¦ ´ãÀ» º¯¼ö
	unsigned int event_cnt = 0; // Á¾¸ñ °¹¼öÀÇ Ä«¿îÆ® ¿ëµµ
	unsigned int max_cnt = 0;
	unsigned int event_select;
	unsigned int cnt = 0;
	unsigned int event_add = 0 ,cand_add = 0;


	system("cls");
	PlaySound(TEXT("main.wav"), NULL, SND_FILENAME | SND_ASYNC);
	setColor(DAKR_YELLOW);
	printf("    ¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á \n");
	printf("    ¡á ÀÌ»óÇü ¿ùµåÄÅ v1.0 ¡á \n");
	printf("    ¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á \n");

	event = fopen("event.txt", "r");
	if (event == NULL)
	{
		setColor(RED);
		printf("\a [ERROR] Á¾¸ñ ÆÄÀÏÀ» ºÒ·¯¿ÀÁö ¸øÇÏ¿´½À´Ï´Ù.");
		return -1;
	}

	setColor(BLUE);

	printf("\n    ¡á¡á¡á¡á¡á\n");
	printf("    ¡á Á¾¸ñ ¡á \n");
	printf("    ¡á¡á¡á¡á¡á \n");
	printf("\n");

	setColor(YELLOW);
	/*ÆÄÀÏ Ãâ·Â ±ÛÀÚÀÇ ÃÖ´ë ±ÛÀÚ¼ö ÆÄ¾Ç*/
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
			event_cnt++; // Á¾¸ñ °¹¼ö¸¦ Ä«¿îÆ®, ¿£ÅÍ °³Çà¹®ÀÚÀÇ °¹¼ö¸¦ ÆÄ¾ÇÇÔ.
		}
		putchar(ch);
	}
	event_cnt++;// ¿£ÅÍÀÇ °¹¼ö¸¦ ÆÄ¾Ç ÇßÀ¸¹Ç·Î while¹®À» ºüÁ®³ª¿À¸é +1À» ÇØÁØ´Ù	
	event_add = (event_cnt + 1);
	cand_add = (event_cnt + 2);
	printf("\n");
	line_printer(max_cnt);
	printf("\n[%d] Á¾¸ñ Ãß°¡\n", event_add );
	line_printer(max_cnt);
	printf("\n[%d] ÈÄº¸ Ãß°¡\n", cand_add );
	line_printer(max_cnt);
	fclose(event);

	// Á¾¸ñ¼±ÅÃ
select:
	setColor(WHITE);
	printf("\n ¹øÈ£¸¦ ¼±ÅÃÇÏ¼¼¿ä: ");
	if (scanf_s("%d", &event_select) == 0) // scanf ÇÔ¼ö´Â ÀÌ»óÇÑ °ªÀÌ µé¾î¿À¸é 0À» ¹ÝÈ¯ÇÑ´Ù.
	{
		setColor(RED);
		rewind(stdin); // Ç¥ÁØ ÀÔ·Â ¹öÆÛ¿¡ ´ã±ä ¸ðµç ¹®ÀÚ¸¦ Á¦°Å
		printf(" \a[ ERROR ] : ÀÔ·ÂÀ» ´Ù½Ã È®ÀÎÇÏ¼¼¿ä!");
		goto select; // ¿¹¿ÜÃ³¸® ¹«Á¶°Ç ºÐ±â¹®
	}

	else if (event_select > cand_add || event_select < 0)
	{
		setColor(RED);
		printf(" \a[ ERROR ] : ¹üÀ§¸¦ ´Ù½Ã È®ÀÎÇÏ¼¼¿ä!");
		rewind(stdin); // Ç¥ÁØ ÀÔ·Â ¹öÆÛ¿¡ ´ã±ä ¸ðµç ¹®ÀÚ¸¦ Á¦°Å
		goto select; // ¿¹¿ÜÃ³¸® ¹«Á¶°Ç ºÐ±â¹®
	}
	return event_select;
}

int ch_max(FILE* TXT) 
{
	int ch; // txt ÆÄÀÏ À§Ä¡Áö½ÃÀÚ¸¦ ´ãÀ» º¯¼ö
	unsigned int ch_cnt = 0, max = 0; // ±ÛÀÚÀÇ °¹¼ö¸¦ Ä«¿îÆ®ÇÒ º¯¼ö, ÃÖ´ñ°ªÀ» ÀúÀå
	
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
	for (int i = 0; i < max; i++) printf("¦¡");
}

Custom user_custom(int select_num ) // user.round°¡ -1¹ÝÈ¯ÀÌ¸é ¿À·ù
{
	int ch;// ÆÄÀÏ À§Ä¡Áö½ÃÀÚ¸¦ ´ãÀ» º¯¼ö
	int cnt = 0;
	int round_max = 0; // roundÀÇ ÃÖ´ë°ªÀ» ´ãÀ» º¯¼ö

	FILE* select_event;
	Custom user; // ±¸Á¶Ã¼ º¯¼ö user
	Custom* p_user = &user; // ±¸Á¶Ã¼ user Æ÷ÀÎÅÍ
	setColor(DARK_GREEN);
	system("cls");
	PlaySound(TEXT("main.wav"), NULL, SND_FILENAME | SND_ASYNC);
	strcpy((p_user->file_txt), select_txt(select_num));
	printf("¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡\n");
	printf("   ¡Ø %s ÆÄÀÏÀ» ¿­°Ú½À´Ï´Ù. ¡Ø \n", (p_user->file_txt));
	printf("¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡\n");
	Sleep(500);
	select_event = fopen(user.file_txt, "r");
	if (select_event == NULL)
	{
		setColor(RED);
		printf("¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡\n");
		printf("\a[ERROR] %s ÆÄÀÏÀ» ºÒ·¯¿ÀÁö ¸øÇÏ¿´½À´Ï´Ù.\n", user.file_txt);
		printf("¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡\n");
		user.round = -1; // -1 ¿À·ù°ª ¹ÝÈ¯
		Sleep(3000);
		return user;
	}
	while (1)
	{
		ch = fgetc(select_event);
		if (ch == ';') break; //ÈÄº¸ÆÄÀÏÀÇ ¸¶Áö¸·ÈÄº¸´Â ³¡¿¡ ;¸¦ Ç¥½ÃÇÏ±â·Î ¾à¼Ó.
		else if (ch == EOF)
		{	
			fclose(select_event);
			setColor(RED);
			printf("¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡\n");
			printf("\a[ERROR] ; Áö½ÃÀÚ°¡ ¾ø½À´Ï´Ù. ÈÄº¸ÆÄÀÏ ¿¡·¯\n");
			printf("¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡\n");
			user.round = -1; // -1 ¿À·ù°ª ¹ÝÈ¯
			Sleep(3000);
			return user;
		}
		else if (ch == '\n') cnt++; // ÈÄº¸ °¹¼ö¸¦ Ä«¿îÆ®
	}
	cnt++;
	fclose(select_event); // ÆÄÀÏ ´Ý±â.
	setColor(SKYBLUE);
	printf("¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡\n");
	printf("   ÃÑ %3d°³ÀÇ ÈÄº¸¸¦ Å½»öÇÏ¿´½À´Ï´Ù.\n", cnt);
	printf("¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡\n");
	user.cand_cnt = cnt;
	round_max = round_find(cnt);
	if (round_max == -1)
	{
		setColor(RED);
		printf("¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡\n");
		printf("\a[ERROR] ÈÄº¸°¡ 2°³ ¹Ì¸¸ÀÇ Àß¸ø µÈ ÈÄº¸ ÆÄÀÏ \n");
		printf("¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡\n");
		user.round = -1;
		Sleep(3000);
		return user;
	}
select:
	setColor(WHITE);
	printf("¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡");
	printf("\n%3d°­ ÀÌÇÏ ºÎÅÍ ½ÃÀÛ ÇÒ ¼ö ÀÖ½À´Ï´Ù.\n", round_max);
	printf("¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡\n");
	int num = round_num(round_max);
	int* ary = (int*)malloc(sizeof(int) * num);
	round_ary(round_max, ary, num);
	printf("\n ¸î °­À» ÁøÇàÇÏ½Ã°Ú½À´Ï±î? : ");

	int round_tmp = 0;

	if (scanf_s("%d", &round_tmp) == 0)
	{
		setColor(RED);
		rewind(stdin); // Ç¥ÁØ ÀÔ·Â ¹öÆÛ¿¡ ´ã±ä ¸ðµç ¹®ÀÚ¸¦ Á¦°Å
		printf("\a [ ERROR ] : ÀÔ·ÂÀ» ´Ù½Ã È®ÀÎÇÏ¼¼¿ä!\n");
		goto select; // ¿¹¿ÜÃ³¸® ¹«Á¶°Ç ºÐ±â¹®
	}
	
	if (round_tmp >= num || round_tmp < 0)
	{
		setColor(RED);
		rewind(stdin); // Ç¥ÁØ ÀÔ·Â ¹öÆÛ¿¡ ´ã±ä ¸ðµç ¹®ÀÚ¸¦ Á¦°Å
		printf("\a [ ERROR ] : °¡´ÉÇÑ ¼ýÀÚ¸¦ ÀÔ·ÂÇÏ¼¼¿ä!\n");
		goto select;
	}

	setColor(YELLOW);
	user.round = ary[round_tmp];

	PlaySound(TEXT("main.wav"), NULL, SND_FILENAME | SND_ASYNC);
	printf("\n¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡\n");
	printf("\n %3d°­À» ¼±ÅÃÇÏ¼Ì½À´Ï´Ù.\n", user.round);
	printf("\n¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡\n");
	Sleep(3000);

	return user;
}

char* select_txt(int select_num)
{
	char buffer[100];
	itoa(select_num, buffer, 10); //  itoa ÇÔ¼ö : intÇüÀ» 10Áø¼ö·Î Ç¥ÇöÇÏ¿© ¹®ÀÚ¿­·Î ´ã´Â´Ù.
	strcat(buffer, ".txt"); // strcat ÇÔ¼ö : ¾Õ¿¡ ÀÎ¼ö·Î ¹ÞÀº ¹®ÀÚ¿­¿¡ µÚÀÇ ÀÎ¼ö·Î ¹ÞÀº ¹®ÀÚ¿­À» ´õÇÑ´Ù.
	return buffer;
}

int round_find(int cand_cnt)
{
	if (cand_cnt <= 1) return -1;
	int x = 2;
	while (1) 
	{
		if (x < cand_cnt) x *= 2; // 2ÀÇ °ÅµìÁ¦°öÀÌ ÀÎ¼öº¸´Ù ÀÛÀ¸¸é °è¼Ó 2¸¦ °öÇÔ
		else if (x == cand_cnt) break; // 2ÀÇ °ÅµìÁ¦°öÀÌ ÀÎ¼ö¿Í °°À¸¸é ¹Ù·Î ºê·¹ÀÌÅ©
		else if (x > cand_cnt) { x /= 2; break;} // 2ÀÇ °ÅµìÁ¦°öÀÌ ÀÎ¼öº¸´Ù Å©¸é 2·Î ³ª´«µÚ ºê·¹ÀÌÅ©
	}
	return x;
}

int round_num(int round_max)
{
	int cnt = 0; // Ä«¿îÆ® ¿ëµµ
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
	printf("¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡\n");
	for (int i = 0; i < num; i++)
	{
		ary[i] = round_max;
		printf("[%d]:%3d°­ | %3d°­À¸·Î ÁøÇà! \n", i, ary[i], ary[i]);
		if(i < (num-1)) printf("¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡\n");
		round_max /= 2;
	}
	printf("¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡\n");
}

/*ÈÄº¸ ¹è¿­ ·£´ýÀ¸·Î Á¤·ÄÇÏ±â*/
char** random_candidate(char* file_txt, int round, int cand_cnt)
{
	system("cls");
	printf("ÈÄº¸¸¦ ¼±Á¤ÇÏ¿© ¹«ÀÛÀ§·Î ¹èÄ¡ ÇÕ´Ï´Ù.\n");
	FILE* random_txt;// ÈÄº¸ ÆÄÀÏ FILE ±¸Á¶Ã¼ º¯¼ö ¼±¾ð
	char* buffer = (char*)malloc(sizeof(char) * 100 ); // ¹®ÀÚ¿­ ÇÑÁÙÀ» ÀÐÀ» ¹öÆÛÀÇ µ¿ÀûÇÒ´ç
	char** candidate = (char*)malloc(sizeof(char) * round); //¹®ÀÚ¿­ ÁÖ¼Ò°ªµéÀÇ ¹è¿­ÀÇ µ¿ÀûÇÒ´ç (Áï, 2Â÷¿ø ¹®ÀÚ¿­ ¹è¿­...)
	int* rand_ary = (int*)malloc(sizeof(int) * cand_cnt); // ·£´ýÇÑ ¼ýÀÚ°ªÀ» ´ãÀ» ¹è¿­

	random_txt = fopen(file_txt, "r");
	if (random_txt == NULL)
	{
		setColor(RED);
		printf("¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡\n");
		printf("\a [ERROR] ÈÄº¸ ÆÄÀÏÀ» ºÒ·¯¿ÀÁö ¸øÇÏ¿´½À´Ï´Ù.");
		printf("¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡\n");
		return;
	}

	srand(time(NULL)); // ·£´ý ÇÔ¼ö ÃÊ±âÈ­


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

				/*";"¹®ÀÚ Á¦°ÅÇÏ±â*/
				if (strstr(buffer,";") != NULL)
				{
					rewind(buffer);
					for (; *buffer != '\n'; buffer++) //Á¾·á ¹®ÀÚ¸¦ ¸¸³¯ ¶§±îÁö ¹Ýº¹
					{
						if (*buffer == ";")//ch¿Í °°Àº ¹®ÀÚÀÏ ¶§
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

	return candidate; //2Â÷¿ø ¹®ÀÚ ¹è¿­....
}
