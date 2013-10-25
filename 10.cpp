#include<cstdio>
#include<vector>
#define MAX 2000000
using namespace std;
int main()
{
	vector<int> primes;
	long long int sum=2;
	primes.push_back(2);
	for(int p=3 ; p < MAX ; p+=2)
	{
		vector<int>::const_iterator iter;
		for(iter = primes.begin(); iter!=primes.end() ; iter++)
		{
			if (p%(*iter) == 0)
				break;
			if ( (*iter) * (*iter) > p)
			{
				iter = primes.end();
				break;
			}
		}
		if(iter == primes.end())
		{
			primes.push_back(p);
			sum+=p;
		}
	}
	printf("%lld\n",sum);
	return 0;
}
