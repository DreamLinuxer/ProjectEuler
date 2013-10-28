#include<stdio.h>
#include<string.h>
const char *str1[]={"one","two","three","four","five","six","seven","eight","nine","ten"\
	,"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
const char *str2[]={"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
const char *str3[]={"hundred","thousand"};

int letters(int num)
{
	if( num>=1000 )
		return letters(num/1000) + strlen(str3[1]) + (num%1000>0 ? 3+letters(num%1000) : 0);
	else if( num>=100 )
		return letters(num/100) + strlen(str3[0]) + (num%100 > 0 ? 3+letters(num%100):0);
	else if( num>=20 )
		return strlen(str2[(num/10)-2]) + (num%10 > 0 ? letters(num%10) : 0);
	return strlen(str1[num-1]);
}
int main()
{
	int ans=0, i;
	for(i=1; i<=1000 ; ++i)
		ans+=letters(i);
	printf("%d\n",ans);
	return 0;
}
