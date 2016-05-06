#include<stdio.h> 
int main(void)
{
	int A, B, C, D, E, F;
	scanf("%d %d", &A, &B);
	C = A + B;
	if (C < 0)
	{
		C = -C;
		printf("-");
	}
	if (C > 999999)
	{
		D = C / 1000000;
		E = (C - D * 1000000) / 1000;
		F = C - D * 1000000 - E * 1000;
		printf("%d,%03d,%03d\n", D, E, F);
	}
	else if (C > 999)
	{
		D = C / 1000;
		E = C - D * 1000;
		printf("%d,%03d\n", D, E);
	}
	else
	{
		printf("%d\n", C);
	}
	return 0;

}
