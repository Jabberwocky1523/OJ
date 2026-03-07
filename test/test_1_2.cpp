#include "bits/stdc++.h"
int a(int i)
{
    if (i % 7 == 0)
    {
        return 0;
    }
    std::string s = std::to_string(i);
    for (char c : s)
    {
        if (c - '0' == 7)
        {
            return 0;
        }
    }
    return i;
}
int main()
{
    int n, sum = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        sum += pow(a(i), 2);
    }
    std::cout << sum;
}