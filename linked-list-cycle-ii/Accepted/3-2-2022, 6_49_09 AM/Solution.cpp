// https://leetcode.com/problems/linked-list-cycle-ii

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    int findposition(ListNode* head,ListNode* slow)
    {
        int count=0;
        while(head!=slow)
        {
            if(head==slow)
                return count;
            head=head->next;
            slow=slow->next;
            count++;
        }
        return count;
    }
    
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        int pos=-1;
        while(slow && fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                pos=findposition(head,slow);
                break;
            }
        }
        if(pos==0)
                return head;
        if(pos!=-1)
        {
            while(pos)
            {
                head=head->next;
                pos--;
            }
            return head;
        }
        return NULL;
    }
};