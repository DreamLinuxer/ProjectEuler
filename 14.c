#include<stdio.h>
int dist[1000000];
int main()
{
	int i, ans=0, len=0;
	for(i=1;i<1000000;++i)
		if(dist[i]==0)
		{
			unsigned long long n = i;
			while(n!=1)
			{
				if(n%2==0)n/=2;
				else n=3*n+1;

				if(n>=1000000 || dist[n]==0)
					dist[i]++;
				else
				{
					dist[i]+=dist[n];
					break;
				}
			}
			if(dist[i]>len)
				ans = i, len = dist[i];
		}
	printf("%d\n",ans);
	return 0;
}
