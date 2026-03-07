#include <bits/stdc++.h>
using namespace std;
#define i64 long long
class block
{
public:
    i64 begin;
    i64 volume;
};
int main()
{
    int n;
    cin >> n;
    block f[101];
    for (int i = 0; i < n; i++)
    {
        block temp;
        cin >> temp.begin >> temp.volume;
        f[i] = temp;
    }
    vector<int> q;
    int temp;
    cin >> temp;
    while (temp != -1)
    {
        /* code */
        q.push_back(temp);
        cin >> temp;
    }
    auto pre = 0;
    for (i64 i : q)
    {
        auto min = -1, a = pre;
        for (int j = 0; j < n; j++)
        {
            if (f[a].volume >= i)
            {
                if (min == -1)
                {
                    min = a;
                }
                if (f[a].volume < f[min].volume)
                {
                    min = a;
                }
            }
            a++;
            if (a == n)
            {
                a = 0;
            }
        }
        if (min == -1)
        {
            continue;
        }
        else if (f[min].volume == i)
        {
            pre = min;
            f[min].volume = 0;
        }
        else
        {
            f[min].volume -= i;
            pre = min;
        }
    }
    for (int i = 0, j = pre; i < n; i++, j = (j + 1) % n)
    {
        if (f[j].volume == 0)
            continue;
        cout << f[j].begin << " " << f[j].volume << endl;
    }
    return 0;
}