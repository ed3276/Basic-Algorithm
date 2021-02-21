#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Partition(std::vector<int> &A, int p, int r)
{
    int x = A[p];
    int i = p, j = r + 1;
    while(1)
    {
        while(A[--j] > x);
        while(A[++i] <= x);
        if(i < j)
        {
            int t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
        else
            return j;
    }
}

void Quicksort(std::vector<int> &A, int p, int r)
{
    if(p < r)
    {
        int j = Partition(A, p, r);
        int t = A[p];
        A[p] = A[j];
        A[j] = t;
        Quicksort(A, p, j);
        Quicksort(A, j+1, r);
    }
}

int main()
{
    cout << "Hello world!" << endl;
    std::vector<int> A = { 27, 99, 0, 8, 13, 64, 86, 16, 7, 10, 88, 25, 90};
    for_each(A.begin(),A.end(),[](int a){ std::cout << a << " ";});
    std::cout << std::endl;
    Quicksort(A, 0, A.size()-1);
    for_each(A.begin(),A.end(),[](int a){ std::cout << a << " ";});
    return 0;
}
