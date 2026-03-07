#include "bits/stdc++.h"
int main()
{
    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int k = 0; k <= 9; k++)
            {
                if (i * 100 + j * 10 + k + j * 100 + k * 11 == 532)
                {
                    std::cout << i << " " << j << " " << k << std::endl;
                }
            }
        }
    }
}