#include <stdio.h>
#include <math.h>

/*� ���� ������ �ø�ó��*/

// ex 1000 -> 1000 / 2000 -> 2000 / 2100 -> 3000 / 1234142 - > 20000000  �̷� ������ ..... 

int num_up (int x);

int main()
{
	int input = 0;
	int output;
	
	printf ("�Է�:");
	scanf("%d",&input);
	output = num_up (input);
	printf ("���: %d",output);
}

int num_up (int x)
{
	int d = 1;
	int tmp = 0;
	
	while (1)
	{
		if (d < x) d*= 10;
		else if (d > x) { d/=10; break; }
		else if (d == x) break;
	}
	
	printf("�ڸ���: %d\n", d);
	
	if ((x%d) == 0) 
	{
		return x;
	}
	
	else if ( (x % d) != 0)
	{
		tmp = ceil (x / d);
		x = (d * tmp) + d;
		return x;
	}
}
