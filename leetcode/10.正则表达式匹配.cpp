/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution
{
public:
    bool match(string s, string p, int i1, int i2)
    {
        auto it1 = s.begin() + i1, it2 = p.begin() + i2;
        while (it1 != s.end() && it2 != p.end())
        {
            if (*(it2 + 1) == '*')
            {
                if (*it1 == *it2 || *it2 == '.')
                {
                    return match(s, p, it1 - s.begin(), it2 - p.begin() + 2) || match(s, p, it1 - s.begin() + 1, it2 - p.begin());
                }
                else
                    it2 += 2;
            }
            else
            {
                if (*it2 == '.' || *it1 == *it2)
                {
                    it2++, it1++;
                }
                else
                {
                    return false;
                }
            }
        }
        if (it2 != p.end())
        {
            int flag = 1;
            while (it2 != p.end())
            {
                if (*it2 != '*')
                {
                    if (*(it2 + 1) == '*')
                    {
                        it2 += 2;
                        continue;
                    }
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (it1 != s.end())
        {
            return false;
        }
        return true;
    }
    bool isMatch(string s, string p)
    {
        return match(s, p, 0, 0);
    };
};
// @lc code=end
