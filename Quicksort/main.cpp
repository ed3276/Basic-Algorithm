#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>& A, int p, int r)
{
	int x = A[r];
	int i = p-1;
	for (int j=p; j<=r-1; ++j) {
		if(A[j]<=x) {
			++i;
			swap(A[i], A[j]);
		}
	}
	swap(A[i+1], A[r])
	return i+1;
}


void quicksort(vector<int>& A, int p, int r) {
{
	while (p < r) {
		int q = partition(A, p, r);
		quicksort(A, p, q-1);
		quicksort(A, q+1, r);
	}
}

int main()
{
    cout << "Hello world!" << endl;
    std::vector<int> A = { 27, 99, 0, 8, 13, 64, 86, 16, 7, 10, 88, 25, 90};
    for_each(A.begin(),A.end(),[](int a){ std::cout << a << " ";});
    std::cout << std::endl;
    quicksort(A, 0, A.size()-1);
    for_each(A.begin(),A.end(),[](int a){ std::cout << a << " ";});
    return 0;
}
