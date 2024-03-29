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
        ListNode* tail=head;
        while(tail->next!=NULL)
        {
            len++;
            tail=tail->next;
        }
        tail->next=head;
        int n=len-k%len;
        for(int i=0;i<n;i++)
            tail=tail->next;
        head=tail->next;
        tail->next=NULL;
        return head;
        
    }
};