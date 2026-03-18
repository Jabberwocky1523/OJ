/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int c = 0;
        ListNode *l3 = new ListNode;
        ListNode *cur = l3;
        while (l1 != nullptr && l2 != nullptr)
        {
            int temp = l1->val + l2->val + c;
            c = temp / 10;
            ListNode *n = new ListNode;
            n->val = temp % 10;
            n->next = nullptr;
            cur->next = n;
            cur = cur->next;
        }
        while (l1 != nullptr)
        {
            int temp = l1->val + c;
            c = temp / 10;
            ListNode *n = new ListNode;
            n->val = temp % 10;
            n->next = nullptr;
            cur->next = n;
            cur = cur->next;
        }
        while (l2 != nullptr)
        {
            int temp = l2->val + c;
            c = temp / 10;
            ListNode *n = new ListNode;
            n->val = temp % 10;
            n->next = nullptr;
            cur->next = n;
            cur = cur->next;
        }
        l3 = l3->next;
        return l3;
    }
};
// @lc code=end
