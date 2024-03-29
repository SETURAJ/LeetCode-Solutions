// https://leetcode.com/problems/rotate-list

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
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
            return NULL;
        int len=1;
        ListNode* last=head;
        while(last->next)
        {
            len++;
            last=last->next;
        }
        last->next=head;
        int a=len-k%len;
        ListNode* tail=head;
        for(int i=0;i<a-1;i++)
            tail=tail->next;
        head=tail->next;
        tail->next=NULL;
        return head;
        
        
    }
};