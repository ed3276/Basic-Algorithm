#include <iostream>
using namespace std;
#include <vector>
int countNum = 0;
//核心代码
void core(vector<int> &vec,int N,int remain,int k)
{
	if (k == N-1)
	{
		vec[k] = remain;
		for (uint32_t i = 0; i < vec.size(); ++i)
		{
			cout << vec[i];
		}
		cout << endl;
		++countNum;
		return;
	}
	for (int i = 0; i <= remain; ++i)
	{
		vec[k] = i;
		core(vec, N, remain - i, k + 1);
	}
}
int main()
{
	int N =4 ;//需要分配资源的个体个数
	int val = 5;//资源总量
	vector<int> vec(N);
	core(vec, N, val, 0);
	cout << "总共有" << " " << countNum << " 中分配方案" << endl;
	return 0;
}
