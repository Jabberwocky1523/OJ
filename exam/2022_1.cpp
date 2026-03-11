#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int arr[n + 10];
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    // sort(0)
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        for (int i = l; i <= r; i++)
        {
            v.push_back(arr[i]);
        }
        int len = v.size();
        int x = 0;
        if (len % 2 != 0)
        {
            x = (arr[len]) / 2 + 1;
        }
        else
        {
            x = (arr[len]) / 2;
        }
        int sum = 0;
        for (int i = l; i <= r; i++)
        {
            sum += abs(x - arr[i]);
        }
        cout << sum << endl;
    }

    return 0;
}