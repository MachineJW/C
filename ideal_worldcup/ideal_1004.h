/*掘褻羹*/
// 餌辨濠陛 摹鷗ж朝 等檜攪蒂 氬擊 餌辨濠 薑曖 濠猿⑽
typedef struct {
	char file_txt[100];
	int round;
} Custom;


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

/*л熱摹樹*/
int ch_max(FILE* TXT); // だ橾 旋濠 熱曖 譆渠 高擊 だ學ж罹 葬欐 л
void line_printer(int max); // 衙偃滲熱煎 菟橫除 熱 虜躑 塭檣擊 虜菟橫邀
Custom user_custom(int select_num); // 餌辨濠曖 薑曖 (摹鷗и だ橾, 賃 鬼 霞ч, 臢蝶おだ橾曖 寡翮 輿模高)
char* select_txt(int select_num); // 摹鷗и 廓�ㄧ� 厥戲賊, txt⑽鷓煎 奩�納媮奡�.
int round_find (int cand_cnt); // �贍� 偎熱蒂 厥戲賊 �贍萼匱� 檜ж曖 陛濰 陛梱遴 塭遴萄蒂 奩�納挬�.


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
		user.round = -1;
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
			user.round = -1;
			Sleep(3000);
			return user;
		}
		else if (ch == '\n') cnt++; // �贍� 偎熱蒂 蘋遴お
	}
	cnt++;
	fclose(select_event); // だ橾 殘晦.
	setColor(SKYBLUE);
	printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式\n");
	printf("   識 %3d偃曖 �贍虜� 鬚儀ж艘蝗棲棻. \n", cnt);
	printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式\n");
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
	printf("   %3d 鬼 檜ж 睡攪 衛濛 й 熱 氈蝗棲棻. \n", round_max);

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