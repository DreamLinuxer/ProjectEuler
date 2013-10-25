#include<cstdio>
#include<vector>
using namespace std;
int main()
{
	vector<int> prime;
	prime.push_back(2);
	for(int p=3 ; prime.size()<10001 ; p+=2)
	{
		int i;
		for(i=0 ; i<prime.size() ; ++i)
			if(p%prime[i] == 0)
				break;
		if(i>=prime.size())
			prime.push_back(p);
	}
	printf("%d\n",prime[10000]);
	return 0;
}
