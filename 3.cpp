#include<cstdio>
#include<vector>
using namespace std;
int main()
{
	long long ans = 0, num = 600851475143;
	vector<long long> prime;
	prime.push_back(2);
	for (long long p = 3;; p+=2 )
	{
		int i=0;
		for(i=0 ; i<prime.size() ; ++i)
			if (p%prime[i] == 0)
				break;
		if(i == prime.size())
			prime.push_back(p);
		if(num%p == 0)
		{
			ans = p;
			while(num%p == 0)
				num/=p;
		}
		if(num == 1)
			break;
	}
	printf("%lld\n",ans);
	return 0;
}
