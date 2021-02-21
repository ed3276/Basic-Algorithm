#include <iostream>
#include <vector>

using namespace std;


std::vector<std::vector<int>> m, s;
void MatrixChain(std::vector<int> &P, int n)
{
    for(int r = 2; r != n; ++r)
    {
        for(int i = 1; i != n-r+1; ++i)
        {
            int j = i + r - 1;
            m[i][j] = m[i+1][j] + P[i-1]*P[i]*P[j];
            s[i][j] = i;
            for(int k = i+1; k != j; ++k)
            {
                int t = m[i][k] + m[k+1][j] + P[i-1]*P[k]*P[j];
                if(t < m[i][j])
                {
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
    }
}



void func(std::vector<int> &P)
{
    for(size_t t = 0; t != P.size(); ++t)
    {
        m.push_back(std::vector<int>(P.size(), 0));
        s.push_back(std::vector<int>(P.size(), t));
    }
    MatrixChain(P, P.size());
}

int RecurMatrixChain(std::vector<int> &P, int i, int j)
{
    int m, s;
    if(i == j)
    {
        m = 0;
        s = i;
        return m;
    }
    m = INT_MAX;
    s = i;
    for(int k = i; k != j; ++k)
    {
        int q = RecurMatrixChain(P, i, k) + RecurMatrixChain(P, k+1, j) + P[i-1]*P[k]*P[j];
        if(q < m)
        {
            m = q;
            s = k;
        }
    }
    std::cout << s << " - ";
    return m;
}
int main()
{
    cout << "Hello world!" << endl;
    std::vector<int> P{30, 35, 15, 5, 10, 20};
    std::cout << RecurMatrixChain(P, 1, P.size()-1) << std::endl;
    func(P);
    std::cout << "m: " << std::endl;
    for(auto &i : m)
    {
        for(auto j : i)
            std::cout << j << "\t\t";
        std::cout << std::endl;
    }
    std::cout << "s: " << std::endl;
    for(auto &i : s)
    {
        for(auto j : i)
            std::cout << j << "\t\t";
        std::cout << std::endl;
    }
    //10, 100, 5, 50, 10, 100, 5, 50
    return 0;
}
