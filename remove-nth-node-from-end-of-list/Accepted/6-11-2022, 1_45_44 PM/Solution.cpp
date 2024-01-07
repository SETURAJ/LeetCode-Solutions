// https://leetcode.com/problems/remove-nth-node-from-end-of-list

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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       if(head==NULL || head->next==NULL)
           return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        for(int i=0;i<n;i++)
            fast=fast->next;
        if(fast!=NULL)
        {
            while(fast && fast->next)
            {
                fast=fast->next;
                slow=slow->next;
            }
            slow->next=slow->next->next;
        }
        else
            return head->next;
        return head;
    }
};