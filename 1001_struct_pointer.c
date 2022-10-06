#include<stdio.h>
#include<string.h>
 
struct candidate {
	char name[20];
	char event[20];
	int winer_cnt;	
};

int main() {
	struct candidate cand;
	strcpy ( cand.name , "케이");
	struct candidate *p = &cand;
	printf ("%s\n",p -> name); // 멤버 접근 연산자 . , 멤버 참조 연산자 -> 
	printf ("%d",p -> winer_cnt);
	return 0;
}
