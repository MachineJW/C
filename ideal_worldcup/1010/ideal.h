/*掘褻羹*/
// 餌辨濠陛 摹鷗ж朝 等檜攪蒂 氬擊 餌辨濠 薑曖 濠猿⑽
typedef struct {
	char file_txt[100];
	int round;
	int cand_cnt;
} Custom;
// 掘褻羹 顫殮營薑曖 Custom


/*翮剪⑽*/
// SetColor л熱縑 檣熱煎 菟橫陛朝 翮剪⑽ 薑曖
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
// 翮剪⑽ 顫殮 營薑曖 Color

/*л熱摹樹*/
int ch_max(FILE* TXT); // だ橾 旋濠 熱曖 譆渠 高擊 だ學ж罹 葬欐 л
void line_printer(int max); // 衙偃滲熱煎 菟橫除 熱 虜躑 塭檣擊 虜菟橫邀
Custom user_custom(int select_num); // 餌辨濠曖 薑曖 (摹鷗и だ橾, 賃 鬼 霞ч, 臢蝶おだ橾曖 寡翮 輿模高)
char* select_txt(int select_num); // 摹鷗и 廓�ㄧ� 厥戲賊, txt⑽鷓煎 奩�納媮奡�.
int round_find (int cand_cnt); // �贍� 偎熱蒂 厥戲賊 �贍� 偎熱 檜ж曖 陛濰 陛梱遴 塭遴萄蒂 奩�納挬�.
int round_num(int round_max); // 譆渠塭遴萄 高擊 厥戲賊 2鬼 梱雖曖 陛棟и 塭遴萄 熱蒂 奩��
void round_ary(int round_max ,int* ary, int num ); // 塭遴萄曖 譆渠高, 寡翮曖 輿模高婁 2睡攪 陛棟и 塭遴萄 熱蒂 啗骯ж罹 厥戲賊 寡翮縑 陛棟и 塭遴萄蒂 盪濰
char** random_candidate(char* file_txt, int round , int cand_cnt);  // 楠渾и �贍葭橉� 寡纂! 檣熱煎 (�贍裟釋牉�, 嶸盪陛 摹鷗и 塭遴萄, 識 �贍� 偎熱)

void setColor(Color text) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}

/*詭檣詭景*/
int main_menu(void) {
	FILE* event; // だ橾 掘褻羹 ん檣攪
	int ch; // txt だ橾 嬪纂雖衛濠蒂 氬擊 滲熱
	unsigned int event_cnt = 0; // 謙跡 偎熱曖 蘋遴お 辨紫
	unsigned int max_cnt = 0;
	unsigned int event_select;
	unsigned int cnt = 0;
	unsigned int event_add = 0 ,cand_add = 0;


	system("cls");
	PlaySound(TEXT("main.wav"), NULL, SND_FILENAME | SND_ASYNC);
	setColor(DAKR_YELLOW);
	printf("    ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥ \n");
	printf("    ﹥ 檜鼻⑽ 錯萄霰 v1.0 ﹥ \n");
	printf("    ﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥ \n");

	event = fopen("event.txt", "r");
	if (event == NULL)
	{
		setColor(RED);
		printf("\a [ERROR] 謙跡 だ橾擊 碳楝螃雖 跤ж艘蝗棲棻.");
		return -1;
	}

	setColor(BLUE);

	printf("\n    ﹥﹥﹥﹥﹥\n");
	printf("    ﹥ 謙跡 ﹥ \n");
	printf("    ﹥﹥﹥﹥﹥ \n");
	printf("\n");

	setColor(YELLOW);
	/*だ橾 轎溘 旋濠曖 譆渠 旋濠熱 だ學*/
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
			event_cnt++; // 謙跡 偎熱蒂 蘋遴お, 縛攪 偃ч僥濠曖 偎熱蒂 だ學л.
		}
		putchar(ch);
	}
	event_cnt++;// 縛攪曖 偎熱蒂 だ學 ц戲嘎煎 while僥擊 緒螳釭螃賊 +1擊 п遽棻	
	event_add = (event_cnt + 1);
	cand_add = (event_cnt + 2);
	printf("\n");
	line_printer(max_cnt);
	printf("\n[%d] 謙跡 蹺陛\n", event_add );
	line_printer(max_cnt);
	printf("\n[%d] �贍� 蹺陛\n", cand_add );
	line_printer(max_cnt);
	fclose(event);

	// 謙跡摹鷗
select:
	setColor(WHITE);
	printf("\n 廓�ㄧ� 摹鷗ж撮蹂: ");
	if (scanf_s("%d", &event_select) == 0) // scanf л熱朝 檜鼻и 高檜 菟橫螃賊 0擊 奩�納挬�.
	{
		setColor(RED);
		rewind(stdin); // ル遽 殮溘 幗ぷ縑 氬曹 賅萇 僥濠蒂 薯剪
		printf(" \a[ ERROR ] : 殮溘擊 棻衛 �挫恉牳撚�!");
		goto select; // 蕨諼籀葬 鼠褻勒 碟晦僥
	}

	else if (event_select > cand_add || event_select < 0)
	{
		setColor(RED);
		printf(" \a[ ERROR ] : 彰嬪蒂 棻衛 �挫恉牳撚�!");
		rewind(stdin); // ル遽 殮溘 幗ぷ縑 氬曹 賅萇 僥濠蒂 薯剪
		goto select; // 蕨諼籀葬 鼠褻勒 碟晦僥
	}
	return event_select;
}

int ch_max(FILE* TXT) 
{
	int ch; // txt だ橾 嬪纂雖衛濠蒂 氬擊 滲熱
	unsigned int ch_cnt = 0, max = 0; // 旋濠曖 偎熱蒂 蘋遴おй 滲熱, 譆渤高擊 盪濰
	
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
	for (int i = 0; i < max; i++) printf("式");
}

Custom user_custom(int select_num ) // user.round陛 -1奩�素抶� 螃盟
{
	int ch;// だ橾 嬪纂雖衛濠蒂 氬擊 滲熱
	int cnt = 0;
	int round_max = 0; // round曖 譆渠高擊 氬擊 滲熱

	FILE* select_event;
	Custom user; // 掘褻羹 滲熱 user
	Custom* p_user = &user; // 掘褻羹 user ん檣攪
	setColor(DARK_GREEN);
	system("cls");
	PlaySound(TEXT("main.wav"), NULL, SND_FILENAME | SND_ASYNC);
	strcpy((p_user->file_txt), select_txt(select_num));
	printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式\n");
	printf("   ≦ %s だ橾擊 翮啊蝗棲棻. ≦ \n", (p_user->file_txt));
	printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式\n");
	Sleep(500);
	select_event = fopen(user.file_txt, "r");
	if (select_event == NULL)
	{
		setColor(RED);
		printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式\n");
		printf("\a[ERROR] %s だ橾擊 碳楝螃雖 跤ж艘蝗棲棻.\n", user.file_txt);
		printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式\n");
		user.round = -1; // -1 螃盟高 奩��
		Sleep(3000);
		return user;
	}
	while (1)
	{
		ch = fgetc(select_event);
		if (ch == ';') break; //�贍裟釋狨� 葆雖虞�贍葩� 部縑 ;蒂 ル衛ж晦煎 擒樓.
		else if (ch == EOF)
		{	
			fclose(select_event);
			setColor(RED);
			printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式\n");
			printf("\a[ERROR] ; 雖衛濠陛 橈蝗棲棻. �贍裟釋� 縑楝\n");
			printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式\n");
			user.round = -1; // -1 螃盟高 奩��
			Sleep(3000);
			return user;
		}
		else if (ch == '\n') cnt++; // �贍� 偎熱蒂 蘋遴お
	}
	cnt++;
	fclose(select_event); // だ橾 殘晦.
	setColor(SKYBLUE);
	printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式\n");
	printf("   識 %3d偃曖 �贍虜� 鬚儀ж艘蝗棲棻.\n", cnt);
	printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式\n");
	user.cand_cnt = cnt;
	round_max = round_find(cnt);
	if (round_max == -1)
	{
		setColor(RED);
		printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式\n");
		printf("\a[ERROR] �贍萼� 2偃 嘐虜曖 澀跤 脹 �贍� だ橾 \n");
		printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式\n");
		user.round = -1;
		Sleep(3000);
		return user;
	}
select:
	setColor(WHITE);
	printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式");
	printf("\n%3d鬼 檜ж 睡攪 衛濛 й 熱 氈蝗棲棻.\n", round_max);
	printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式\n");
	int num = round_num(round_max);
	int* ary = (int*)malloc(sizeof(int) * num);
	round_ary(round_max, ary, num);
	printf("\n 賃 鬼擊 霞чж衛啊蝗棲梱? : ");

	int round_tmp = 0;

	if (scanf_s("%d", &round_tmp) == 0)
	{
		setColor(RED);
		rewind(stdin); // ル遽 殮溘 幗ぷ縑 氬曹 賅萇 僥濠蒂 薯剪
		printf("\a [ ERROR ] : 殮溘擊 棻衛 �挫恉牳撚�!\n");
		goto select; // 蕨諼籀葬 鼠褻勒 碟晦僥
	}
	
	if (round_tmp >= num || round_tmp < 0)
	{
		setColor(RED);
		rewind(stdin); // ル遽 殮溘 幗ぷ縑 氬曹 賅萇 僥濠蒂 薯剪
		printf("\a [ ERROR ] : 陛棟и 璋濠蒂 殮溘ж撮蹂!\n");
		goto select;
	}

	setColor(YELLOW);
	user.round = ary[round_tmp];

	PlaySound(TEXT("main.wav"), NULL, SND_FILENAME | SND_ASYNC);
	printf("\n式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式\n");
	printf("\n %3d鬼擊 摹鷗ж樟蝗棲棻.\n", user.round);
	printf("\n式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式\n");
	Sleep(3000);

	return user;
}

char* select_txt(int select_num)
{
	char buffer[100];
	itoa(select_num, buffer, 10); //  itoa л熱 : int⑽擊 10霞熱煎 ル⑷ж罹 僥濠翮煎 氬朝棻.
	strcat(buffer, ".txt"); // strcat л熱 : 擅縑 檣熱煎 嫡擎 僥濠翮縑 菴曖 檣熱煎 嫡擎 僥濠翮擊 渦и棻.
	return buffer;
}

int round_find(int cand_cnt)
{
	if (cand_cnt <= 1) return -1;
	int x = 2;
	while (1) 
	{
		if (x < cand_cnt) x *= 2; // 2曖 剪蛙薯培檜 檣熱爾棻 濛戲賊 啗樓 2蒂 培л
		else if (x == cand_cnt) break; // 2曖 剪蛙薯培檜 檣熱諦 偽戲賊 夥煎 粽溯檜觼
		else if (x > cand_cnt) { x /= 2; break;} // 2曖 剪蛙薯培檜 檣熱爾棻 觼賊 2煎 釭換菴 粽溯檜觼
	}
	return x;
}

int round_num(int round_max)
{
	int cnt = 0; // 蘋遴お 辨紫
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
	printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式\n");
	for (int i = 0; i < num; i++)
	{
		ary[i] = round_max;
		printf("[%d]:%3d鬼 | %3d鬼戲煎 霞ч! \n", i, ary[i], ary[i]);
		if(i < (num-1)) printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式\n");
		round_max /= 2;
	}
	printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式\n");
}

/*�贍� 寡翮 楠渾戲煎 薑溺ж晦*/
char** random_candidate(char* file_txt, int round, int cand_cnt)
{
	system("cls");
	printf("�贍虜� 摹薑ж罹 鼠濛嬪煎 寡纂 м棲棻.\n");
	FILE* random_txt;// �贍� だ橾 FILE 掘褻羹 滲熱 摹樹
	char* buffer = (char*)malloc(sizeof(char) * 100 ); // 僥濠翮 и還擊 檗擊 幗ぷ曖 翕瞳й渡
	char** candidate = (char*)malloc(sizeof(char) * round); //僥濠翮 輿模高菟曖 寡翮曖 翕瞳й渡 (闊, 2離錳 僥濠翮 寡翮...)
	int* rand_ary = (int*)malloc(sizeof(int) * cand_cnt); // 楠渾и 璋濠高擊 氬擊 寡翮

	random_txt = fopen(file_txt, "r");
	if (random_txt == NULL)
	{
		setColor(RED);
		printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式\n");
		printf("\a [ERROR] �贍� だ橾擊 碳楝螃雖 跤ж艘蝗棲棻.");
		printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式\n");
		return;
	}

	srand(time(NULL)); // 楠渾 л熱 蟾晦��


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

				/*";"僥濠 薯剪ж晦*/
				if (strstr(buffer,";") != NULL)
				{
					rewind(buffer);
					for (; *buffer != '\n'; buffer++) //謙猿 僥濠蒂 虜陳 陽梱雖 奩犒
					{
						if (*buffer == ";")//ch諦 偽擎 僥濠橾 陽
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

	return candidate; //2離錳 僥濠 寡翮....
}
