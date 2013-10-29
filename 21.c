#include<stdio.h>
#include<string.h>
int d(int n)
{
	int i, j, sum=1;
	for(i=2;i*i<=n;++i)
		if(n%i==0)
		{
			sum+=i;
			j=n/i;
			if(i!=j)
				sum+=j;
		}
	return sum;
}
int main()
{
	int i, ans=0;
	for(i=2;i<10000;++i)
	{
		int j = d(i);
		if(j>i&&d(j)==i)
			ans+=i+j;
	}
	printf("%d\n",ans);
	return 0;
}
