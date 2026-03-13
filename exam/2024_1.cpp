#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    long long n, newflowers, target, full, partial;
    cin >> n;
    vector<long long> flowers(n), diff;
    long long dp = 0, min_num = INT64_MAX, max_num = INT64_MIN;
    for (long long i = 0; i < n; i++)
    {
        cin >> flowers[i];
    }
    cin >> newflowers >> target >> full >> partial;
    for (long long i : flowers)
    {
        if (i >= target)
        {
            dp += full;
        }
        else
        {
            if (i < min_num)
                min_num = i;
            diff.push_back(i);
        }
    }
    if (min_num < target)
    {
        max_num = dp + min_num * partial;
    }
    else
    {
        max_num = dp;
    }
    sort(diff.begin(), diff.end(), greater<long long>());
    // for (long long ll : diff)
    // {
    //     cout << ll << " ";
    // }
    // cout << endl;
    long long prediff[diff.size()];
    prediff[diff.size() - 1] = 0;
    for (int i = diff.size() - 2; i >= 0; i--)
    {
        prediff[i] = prediff[i + 1] + (diff[i] - diff[i + 1]) * (diff.size() - 1 - i);
        // cout << prediff[i] << " ";
    }
    // cout << endl;
    long long pre = 0;
    for (long long i = 0; i < diff.size(); i++)
    {
        long long p = 1;
        pre += target - diff[i];
        if (pre > newflowers)
        {
            break;
        }
        long long cur = (i + 1) * full, last = newflowers - pre, it = i + 1;
        if (i == diff.size() - 1)
        {
            max_num = max(max_num, cur + dp);
            break;
        }
        while (last < prediff[it])
        {
            it++;
        }
        last -= prediff[it];
        // cout << it << " ";
        // cout << it << " " << p << " " << endl;
        diff[it] += last / (diff.size() - it);
        if (diff[it] >= target)
        {
            cur += (target - 1) * partial;
        }
        else
        {
            cur += diff[it] * partial;
        }
        max_num = max(max_num, cur + dp);
        cout << max_num << endl;
    }
    cout << max_num;
    return 0;
}