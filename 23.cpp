#include<cstdio>
#include<vector>
using namespace std;
char mark[28124];
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
	int i, j, t, ans=0;
	vector<int> nums;
	for(i=12; i<28124 ; ++i)
		if(d(i)>i)
			nums.push_back(i);

	for(i=0;i<nums.size();++i)
		for(j=i;j<nums.size();++j)
			if( (t=nums[i]+nums[j]) < 28124 )
				mark[t]=1;

	for(i=1;i<28124;++i)
		ans+=(mark[i]?0:i);
	printf("%d\n",ans);
	return 0;
}
