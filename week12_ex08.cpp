#include <stdio.h>
long factorial(int n){
	printf("factorial(%d)\n", n);
	if (n <= 1) return 1;
	else return n * factorial(n - 1);
}
int main(void)
{
	int n;
	long f;
	printf("정수를 입력하시오:");
	scanf("%d", &n);
	f = factorial(n);
	printf("%d!은 %d입니다. \n", n, f);
	return 0;
}