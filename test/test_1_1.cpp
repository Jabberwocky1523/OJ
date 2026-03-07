#include "iostream"
#include "string"
#include "algorithm"
#include "cmath"
#include "functional"
using namespace std;
int a(int n)
{
    int nn = pow(n, 2);
    std::string snn = std::to_string(nn);
    for (int i = 0; i < snn.length() / 2; i++)
    {
        if (snn[i] != snn[snn.length() - i - 1])
        {
            return -1;
        }
    }
    return n;
}
int main()
{
    for (int i = 1; i <= 256; i++)
    {
        if (a(i) != -1)
        {
            std::cout << i << std::endl;
        }
    }
}