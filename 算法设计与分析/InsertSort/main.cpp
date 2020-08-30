#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
void InsertSort(vector<int> &A, int n);
void MergeSort(vector<int> &A, int p, int r);

int main()
{
    cout << "Hello world!" << endl;
    const int n = 1000000000;
    vector<int> A;
    for(int i=0; i != n; ++i)
        A.push_back(i);
    random_shuffle(A.begin(),A.end());
    //InsertSort(A,n);
    //MergeSort(A, 0, n-1);
    return 0;
}

void InsertSort(vector<int> &A, int n)
{
    for(int j = 1; j< n; ++j)
    {
        int x = A[j];
        int i = j - 1;
        while(i >= 0 && x < A[i])
        {
            A[i+1] = A[i];
            i = i - 1;
        }
        A[i+1] = x;
    }
}

void Merge(vector<int> &A, int p, int q, int r)
{
    int* B = new int[q-p+1];
    int* C = new int[r-q];
    int x = q-p+1, y = r-q;
    for(int i=p,j=0; i<=q; ++i,++j)
        B[j] = A[i];
    for(int i=q+1,j=0; i<=r; ++i,++j)
        C[j] = A[i];
    int i = 0, j = 0, k = p;
    while(i<x && j<y)
    {
        if(B[i]<=C[j])
        {
            A[k] = B[i];
            ++i;
        }
        else
        {
            A[k] = C[j];
            ++j;
        }
        ++k;
    }
    if(i==x)
        while(j<y) A[k++] = C[j++];
    else
        while(i<x) A[k++] = B[i++];
    delete [] B;
    delete [] C;
}
void MergeSort(vector<int> &A, int p, int r)
{
    int q;
    if(p < r)
    {
        q = (p + r)/2;
        MergeSort(A, p, q);
        MergeSort(A, q+1, r);
        Merge(A, p, q, r);
    }

}
