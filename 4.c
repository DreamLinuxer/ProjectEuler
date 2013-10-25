#include<stdio.h>
int max(int a,int b)
{
	return (a>b ? a : b);
}
int check(int num)
{
	static char buffer[16];
	char *p,*q;
	sprintf(buffer,"%d",num);
	for(p=buffer, q=buffer+strlen(buffer)-1 ; p<q ; ++p, --q)
		if (*p != *q)
			return 0;
	return 1;
}
int main()
{
	int a,b,ans = 0;
	for(a=100 ; a<1000 ; ++a)
		for(b=100; b<1000 ; ++b)
			ans = (check(a*b) ? max(ans,a*b) : ans);
	printf("%d\n",ans);
	return 0;
}
