#include<stdio.h>
#include<string.h>
int pos[1000];
int main()
{
	int i, len = 0, r, l, num;
	for(i=1000 ; i>len ; --i)
	{
		memset(pos,0,sizeof(pos));
		for(r = 1, l = 0; r && pos[r]==0 ; ++l)
		{
			pos[r] = l;
			r = (r*10)%i;
		}
		if(r && len<(l-pos[r]))
		{
			len = l-pos[r];
			num=i;
		}
	}
	printf("%d\n",num);
	return 0;
}
