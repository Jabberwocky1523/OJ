/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        string ans;
        int max_num = INT_MIN;
        for (int i = 1; i < s.length() - 1; i++)
        {
            int l = i - 1, r = i + 1;
            while (l >= 0 && s[l] == s[i])
                l--;
            while (r < s.length() && s[r] == s[i])
                r++;
            while (l >= 0 && r < s.length() && s[l] == s[r])
            {
                l--, r++;
            }
            r--, l++;
            if (r - l + 1 > max_num)
            {
                max_num = r - l + 1;
                ans = s.substr(l, r - l + 1);
            }
        }
        return ans;
    }
};
// @lc code=end
