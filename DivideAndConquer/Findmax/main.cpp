#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <list>

using namespace std;

std::pair<int, int> Findmax(std::vector<int> &L)
{
    std::pair<int, int> ans(0, -1);
    if(L.size() > 0)
    {
        ans.first = L[0];
        ans.second = 0;
        for(size_t i = 1; i < L.size(); ++i)
        {
            if(ans.first < L[i])
            {
                ans.first = L[i];
                ans.second = i;
            }
        }
    }
    return ans;
}
std::pair<int, int> Findmin(std::vector<int> &L)
{
    std::pair<int, int> ans(0, -1);
    if(L.size() > 0)
    {
        ans.first = L[0];
        ans.second = 0;
        for(size_t i = 1; i < L.size(); ++i)
        {
            if(ans.first > L[i])
            {
                ans.first = L[i];
                ans.second = i;
            }
        }
    }
    return ans;
}


std::vector<std::pair<int, int>> Find_2_8(std::vector<int> &L)
{
    std::vector<std::pair<int, int>> ans;
    if(L.size() > 0)
    {
        if(L.size() == 1)
        {
            ans.push_back(std::pair<int, int>(L[0], 0));
            ans.push_back(std::pair<int, int>(L[0], 0));
        }
        else
        {
            ans.push_back(Findmax(L));
            L.erase(L.begin() + ans[0].second);
            ans.push_back(Findmin(L));
            if(ans[1].second >= ans[0].second)
                ++ans[1].second;
        }
    }
    return ans;
}

std::pair<int, int> FindMaxMin(std::vector<int> &L)
{
    std::pair<int, int> ans;
    std::vector<int> maxv, minv;
    if(!L.size()) return ans;
    if(L.size() == 1)
    {
        ans = {L[0], L[0]};
        return ans;
    }
    for(size_t idx= 0; idx != L.size()/2; ++idx)
    {
        if(L[idx*2] > L[idx*2+1])
        {
            maxv.push_back(L[idx*2]);
            minv.push_back(L[idx*2+1]);
        }
        else
        {
            maxv.push_back(L[idx*2+1]);
            minv.push_back(L[idx*2]);
        }
    }
    ans.first = Findmax(maxv).first;
    ans.second = Findmin(minv).first;
    return ans;
}

struct elem
{
    elem() : value(0) { };
    explicit elem(int v) : value(v) { }
    elem(const elem &e) : value(e.value) { }
    elem &operator=(const elem &e)  { value = e.value; return *this; }
    ~elem() { }
    int value;
    std::list<int> li;
};
int FindSecond(std::vector<int> &L)
{
    std::vector<elem> T;
    for(size_t idx = 0; idx != L.size(); ++idx)
        T.push_back(elem(L[idx]));
    if(T.size() < 2)
        std::runtime_error("less than 2 element.");
    while(T.size() > 1)
    {
        std::vector<elem> tmp;
        for(size_t i = 0; i != T.size()/2; ++i)
        {
            if(T[i*2].value > T[i*2+1].value)
            {
                T[i*2].li.insert(T[i*2].li.begin(), T[i*2+1].value);
                tmp.push_back(T[i*2]);
            }
            else
            {
                T[i*2+1].li.insert(T[i*2+1].li.begin(), T[i*2].value);
                tmp.push_back(T[i*2+1]);
            }
        }
        if(T.size() % 2)
            tmp.push_back(T.back());
        T = tmp;
    }
    int max = *T[0].li.begin();
    for(std::list<int>::iterator it = T[0].li.begin(); it != T[0].li.end(); ++it)
    {
        if(*it > max)
            max = *it;
    }
    return max;
}

int main()
{
    cout << "Hello world!" << endl;
    std::vector<int> A = { 27, 99, 0, 8, 13, 64, 86, 16, 7, 10, 88, 25, 90};
    for_each(A.begin(),A.end(),[](int a){ std::cout << a << " ";});std::cout << std::endl;
    std::pair<int, int> ans = Findmax(A);
    std::cout << "max value: " << ans.first << " , index: " << ans.second << std::endl;
    ans = Findmin(A);
    std::cout << "min value: " << ans.first << " , index: " << ans.second << std::endl;

    ans = FindMaxMin(A);
    std::cout << "max value: " << ans.first << " , min value: " << ans.second << std::endl;

    int second = FindSecond(A);
    std::cout << "second element is " << second << std::endl;
    std::vector<std::pair<int, int>> ret = Find_2_8(A);
    for_each(ret.begin(),ret.end(),[](std::pair<int, int> a){ std::cout << "(" << a.first << ", " << a.second << ")" << " ";});std::cout << std::endl;
    return 0;
}
