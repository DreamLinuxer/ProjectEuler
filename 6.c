#include<stdio.h>
int square(int num)
{
	return num*num;
}
int main()
{
	int sum_of_square = 100 * (100+1) * (2*100+1) / 6;
	int square_of_sum = square((1 + 100) * 100 / 2);
	printf("%d\n",square_of_sum-sum_of_square);
	return 0;
}
