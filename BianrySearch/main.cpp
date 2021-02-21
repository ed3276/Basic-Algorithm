#include <iostream>
#include <vector>

using namespace std;

template <typename G> int BinarySearch(std::vector<G> &T, G x)
{
    int l = 0, r = T.size()-1, m = 0;
    while(l <= r)
    {
        m = (l + r)/2;
        if(T[m] == x)
            return x;
        else if(T[m] > x)
            r = m - 1;
        else
            l = m + 1;
    }
    return -1;
}


int main()
{
    cout << "Hello world!" << endl;
    std::vector<int> T = {1, 2, 3, 4, 5, 6};
    int target = 6;
    if(BinarySearch(T, target) != -1)
        std::cout << "has find " << target << " in T" << std::endl;
    else
        std::cout << "not find " << target << " in T" << std::endl;
    return 0;
}
