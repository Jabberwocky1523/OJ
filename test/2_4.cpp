#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> a;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    for (int i = 0; i < K; i++)
    {
        vector<int> b, c;
        for (int i = 0; i < N; i++)
        {
            int temp;
            cin >> temp;
            b.push_back(temp);
        }
        auto ita = a.begin(), itb = b.begin();
        while (itb != b.end())
        {
            /* code */
            if (ita != a.end())
            {
                c.push_back(*ita);
                ita++;
            }
            while (1)
            {
                /* code */
                if (c.empty())
                {
                    break;
                }
                if (*itb == *c.begin())
                {
                    itb++;
                    c.erase(c.begin());
                }
                else if (*itb == *(c.end() - 1))
                {
                    itb++;
                    c.erase(c.end() - 1);
                }
                else if (ita != a.end())
                {
                    break;
                }
                else
                {
                    itb = b.end();
                    break;
                }
            }
        }
        if (c.empty())
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
    return 0;
}