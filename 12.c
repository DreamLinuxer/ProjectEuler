#include<stdio.h>
int divisor(unsigned long long num)
{
	int ans;
	unsigned long long i;
	for(i=1, ans=0;i*i<=num;++i)
		if(num%i==0)
			ans += (i*i==num ? 1 : 2);
	return ans;
}
int main()
{
	unsigned long long tri_num, i;
	for( tri_num = 1, i=2 ; ; )
	{
		if (divisor(tri_num)>=500)
		{
			printf("%llu\n",tri_num);
			break;
		}
		tri_num+=i;
		++i;
	}
	return 0;
}
