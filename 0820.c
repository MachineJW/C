#include<stdio.h>
int squared(int x, int y);

int main()
{
	int a,n,res;
	
	
	printf("�����Է�:");
	scanf("%d",&a);
	printf("�������Է�:");
	scanf("%d",&n);
	printf("����: %d , ������: %d",a,n);
	res = squared(a,n);
	printf("\n���:%d",res);	
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
