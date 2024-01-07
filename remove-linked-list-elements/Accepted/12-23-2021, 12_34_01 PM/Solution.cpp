// https://leetcode.com/problems/remove-linked-list-elements

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *temp1=head,*nex=NULL,*temp=NULL;
        while(head && head->val==val)
        {
            head=head->next;
            delete(temp1);
            temp1=head;
        }
        if(!head)
            return head;
        nex=head->next;
        while(nex)
        {
            if(nex->val==val)
            {
                temp1->next=nex->next;
                temp=nex;
                nex=nex->next;
                delete(temp);
            }
            else
            {
                nex=nex->next;
                temp1=temp1->next;
            }
        }
        return head;
        
    }
};