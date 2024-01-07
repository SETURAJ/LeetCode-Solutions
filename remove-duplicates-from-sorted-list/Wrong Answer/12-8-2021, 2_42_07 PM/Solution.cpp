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
        ListNode *curr=new ListNode();
        curr=head;
        ListNode *temp=new ListNode();
        temp=head->next;
        while(temp->next!=NULL)
        {
            if(curr==temp)
            {
                curr->next=temp->next;
                curr=curr->next;
                temp=curr->next;
            }
            else
            {
                curr=curr->next;
                temp=temp->next;
            }
        
        }
        return curr;
    }
};