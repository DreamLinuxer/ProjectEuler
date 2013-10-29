#include<stdio.h>
int day[] = {31,28,31,30,31,30,31,31,30,31,30,31};
int leap_year(int y)
{
	return (y%400==0 ? 1 : (y%100==0 ? 0 : (y%4==0 ? 1 : 0)));
}
int days(int m,int y)
{
	return day[m-1]+(m==2&&leap_year(y)?1:0);
}
int main()
{
	int d=1, m=1, y=1901, wd=2, ans=0;
	while(y<2001)
	{
		if(wd==0)
			ans++;
		wd = (wd+days(m,y))%7;
		++m;
		if(m>12)
			m=1, ++y;
	}
	printf("%d\n",ans);
	return 0;
}
