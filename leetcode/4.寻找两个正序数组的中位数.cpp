// /*
//  * @lc app=leetcode.cn id=4 lang=cpp
//  *
//  * [4] 寻找两个正序数组的中位数
//  */

// // @lc code=start
// // @lc code=end
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int total = (nums1.size() + nums2.size() + 1) / 2;
        if (nums1.size() > nums2.size())
        {
            swap(nums1, nums2);
        }
        int l = 0, r = nums1.size() - 1;
        while (l <= r)
        {
            int i = l + (r - l + 1) / 2;
            int j = total - i;
            if (i > 0 && nums1[i - 1] > nums2[j])
            {
                r = i - 1;
            }
            else if (j > 0 && nums2[j - 1] > nums1[i])
            {
                l = i + 1;
            }
            else
            {
                break;
            }
        }
        int i = l + (r - l + 1) / 2;
        int j = total - i;
        int n1 = i == nums1.size() ? INT_MAX : nums1[i],
            n2 = j == nums2.size() ? INT_MAX : nums2[j],
            n3 = i == 0 ? INT_MIN : nums1[i - 1],
            n4 = j == 0 ? INT_MIN : nums2[j - 1];
        cout << i << " " << j << endl;
        // cout << n1 << endl
        //      << n2 << endl
        //      << n3 << endl
        //      << n4;
        if ((nums1.size() + nums2.size()) % 2 == 0)
        {
            double d1 = min(n1, n2), d2 = max(n3, n4);
            return (d1 + d2) / 2;
        }
        else
        {
            double d = max(n3, n4);
            return d;
        }
    }
};
int main()
{
    ios::sync_with_stdio(false);
    int m, n;
    cin >> m >> n;
    vector<int> nums1(m), nums2(n);
    for (int i = 0; i < m; i++)
    {
        cin >> nums1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> nums2[i];
    }
    Solution s;
    cout << s.findMedianSortedArrays(nums1, nums2);
    return 0;
}