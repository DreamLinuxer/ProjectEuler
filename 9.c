#include<stdio.h>
int gcd(int m, int n)
{
	int tmp;
	while (n != 0)
	{
		tmp = m % n;
		m = n;
		n = tmp;
	}
	return m;
}
int main()
{
	int m,n,a,b,c;
	for(m = 1 ; m < 1000 ; ++m)
		for(n = 1 ; n < m ; ++n)
			if(gcd(n,m) == 1)
			{
				a = m*m - n*n;
				b = 2*m*n;
				c = m*m + n*n;
				if (1000%(a+b+c) == 0)
				{
					int k = 1000/(a+b+c);
					a = k*a, b = k*b, c = k*c;
					printf("%dx%dx%d = %d\n%d+%d=%d\n",a,b,c,a*b*c,a*a,b*b,c*c);
					return 0;
				}
			}
	return 0;
}
