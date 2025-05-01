/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
    ListNode *partition(ListNode *head, int x)
    {
        if (head == NULL || head->next == NULL)
        {
            return head; // No duplicates to remove, return the list as is
        }
        ListNode *list1 = new ListNode(0, nullptr);
        ListNode *list2 = new ListNode(0, nullptr);
        ListNode *small = list1;
        ListNode *big = list2;
        while(head != nullptr)
        {
            if(head->val < x)
            {
                small->next = head;
                small = small->next;
            }
            else 
            {
                big->next = head;
                big = big->next;
            }
            head = head->next;
        }
        small->next = list2->next;
        big->next = nullptr;
        ListNode* res = list1->next;
        return res;
    }
};
// @lc code=end
