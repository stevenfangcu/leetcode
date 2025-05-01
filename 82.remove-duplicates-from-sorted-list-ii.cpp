/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head; // No duplicates to remove, return the list as is
        }
        ListNode *dummy = new ListNode(0, head);
        ListNode *prev = dummy;
        ListNode *curr = head;
        while (curr != NULL)
        {
            if (curr->next != NULL && curr->val == curr->next->val)
            {
                while (curr->next != NULL && curr->val == curr->next->val)
                {
                    curr = curr->next;
                }
                prev->next = curr->next;
            } 
            else {
                // If no duplicate is found, move 'prev' to the current node
                prev = curr;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};
// @lc code=end
