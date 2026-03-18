/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> vv;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= 0)
            {
                return vv;
            }
            int j = i + 1, k = nums.size() - 1;
            while (j < k)
            {
                int cur = nums[i] + nums[j] + nums[k];
                if (cur > 0)
                {
                    while (nums[k - 1] != nums[k] && j < k)
                        k--;
                }
                else if (cur < 0)
                {
                    while (nums[j + 1] != nums[j] && j < k)
                        j++;
                }
                else
                {
                    vector<int> temp;
                    temp.push_back(nums[i]), temp.push_back(nums[j]), temp.push_back(nums[k]);
                    vv.push_back(temp);
                    while (nums[j + 1] != nums[j] && j < k)
                        j++;
                }
            }
        }
        return vv;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    Solution s;
    vector<int> v;
    int temp;
    while (cin >> temp)
    {
        v.push_back(temp);
    }
    s.threeSum(v);
    return 0;
}

// @lc code=end
