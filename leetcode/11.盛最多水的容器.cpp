/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution
{
public:
    int area(vector<int> &height, int l, int r)
    {
        return min(height[l], height[r]) * (r - l + 1);
    }
    int maxArea(vector<int> &height)
    {
        int l = 0, r = height.size() - 1, ans = INT_MIN, flag = 1;
        while (l < r && flag)
        {
            flag = 0;
            int cur = area(height, l, r);
            ans = max(cur, ans);
            while (area(height, l + 1, r) > cur && l < r)
            {
                l++;
                cur = area(height, l, r);
                flag = 1;
            }
            while (area(height, l, r - 1) > cur && l < r)
            {
                r--;
                cur = area(height, l, r);
                flag = 1;
            }
        }
        return ans;
    }
};
// @lc code=end
