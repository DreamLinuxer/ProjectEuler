#include<stdio.h>
int check(int num)
{
	int i;
	for(i=2 ; i<=20 ; ++i)
		if(num%i != 0)
			return 0;
	return 1;
}
int main()
{
	int num;
	for (num = 2050 ; !check(num) ; num += 10);
	printf("%d\n",num);
	return 0;
}
