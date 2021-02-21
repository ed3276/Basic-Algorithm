#include <iostream>
#include <vector>
#include <utility>

using namespace std;

std::vector<std::vector<std::pair<int, int>>> InvestProblem(std::vector<std::vector<int>> &f)
{
    std::vector<std::vector<std::pair<int, int>>> Fx;
    for(size_t i = 0; i != f.size(); ++i)
        Fx.push_back(std::vector<std::pair<int, int>>(f[0].size(), std::pair<int, int>(0, 0)));
    for(size_t i = 0; i != f[0].size(); ++i)
    {
        Fx[0][i].first = f[0][i];
        Fx[0][i].second = i;
    }
    for(size_t r = 1; r != f.size(); ++r)
    {
        for(size_t i = 1; i != f[0].size(); ++i)
        {
            Fx[r][i].first = f[r][0] + Fx[r-1][i].first;
            Fx[r][i].second = 0;
            for(size_t j = 1; j != i+1; ++j)
            {
                int t = f[r][j] + Fx[r-1][i-j].first;
                if(t > Fx[r][i].first)
                {
                    Fx[r][i].first = t;
                    Fx[r][i].second = j;
                }
            }
        }
    }
    return Fx;
}

int main()
{
    cout << "Hello world!" << endl;
    std::vector<std::vector<int>> f = {
    { 0, 11, 12, 13, 14, 15},
    { 0, 0, 5, 10, 15, 20},
    { 0, 2, 10, 30, 32, 40},
    { 0, 20, 21, 22, 23, 24}
    };
    std::vector<std::vector<std::pair<int, int>>> F = InvestProblem(f);
    for(auto &r : F)
    {
        for(auto c : r)
            std::cout << "(" << c.first << ", " << c.second << ")" << "\t\t";
        std::cout << std::endl;
    }
    return 0;
}
