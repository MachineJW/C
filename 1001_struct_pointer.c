#include<stdio.h>
#include<string.h>
 
struct candidate {
	char name[20];
	char event[20];
	int winer_cnt;	
};

int main() {
	struct candidate cand;
	strcpy ( cand.name , "����");
	struct candidate *p = &cand;
	printf ("%s\n",p -> name); // ��� ���� ������ . , ��� ���� ������ -> 
	printf ("%d",p -> winer_cnt);
	return 0;
}
