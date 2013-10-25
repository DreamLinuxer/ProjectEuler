#include<stdio.h>
int main()
{
	long long sum,a1,a2,a3;
	for(a1 = 1, a2 = 1, a3 = 2, sum = 0; a3<4000000 ;)
	{
		sum+=(a3%2==0 ? a3 : 0);
		a1 = a2;
		a2 = a3;
		a3 = a1 + a2;
	}
	printf("%lld\n",sum);
	return 0;
}
