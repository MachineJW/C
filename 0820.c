#include<stdio.h>
int squared(int x, int y);

int main()
{
	int a,n,res;
	
	
	printf("숫자입력:");
	scanf("%d",&a);
	printf("제곱수입력:");
	scanf("%d",&n);
	printf("숫자: %d , 제곱수: %d",a,n);
	res = squared(a,n);
	printf("\n결과:%d",res);	
	return 0;
}

int squared(int x, int y)
{
	int result = 1;
	int i;
	
	for(i = 0; i < y ; i++)
	{
	 result *= x;	
	}
	return result;
}
