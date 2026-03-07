#include "bits/stdc++.h"
std::vector<int> int_to_vector(int i)
{
    std::vector<int> ans;
    std::string temp = std::to_string(i);
    for (char c : temp)
    {
        ans.push_back(c - '0');
    }
    return ans;
}
int a(int n)
{
    int nn = n * 9;
    std::vector<int> i1 = int_to_vector(n);
    std::vector<int> i2 = int_to_vector(nn);
    for (int i = 0; i < 4; i++)
    {
        if (i1[i] != i2[3 - i])
        {
            return 0;
        }
    }
    return n;
}

int main()
{
    for (int i = 1000; i <= 10000 / 9 + 1; i++)
    {
        if (a(i) != 0)
        {
            std::cout << i << std::endl;
        }
    }
}