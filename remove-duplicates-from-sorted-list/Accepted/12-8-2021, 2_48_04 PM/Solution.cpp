// https://leetcode.com/problems/remove-duplicates-from-sorted-list

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
    ListNode* deleteDuplicates(ListNode* head) {
       ListNode *temp=head;
        while(head!=NULL)
        {
            if(head->next && head->val==head->next->val)
            {
                ListNode *node=head->next;
                head->next=head->next->next;
                delete(node);
            }
            else
            {
                head=head->next;
            }
        }
        return temp;
    }
};