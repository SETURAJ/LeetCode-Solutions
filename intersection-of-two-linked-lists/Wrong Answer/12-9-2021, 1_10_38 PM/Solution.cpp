// https://leetcode.com/problems/intersection-of-two-linked-lists

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
    void reverse(ListNode **head)
    {
        ListNode *prev=NULL;
        ListNode *curr=NULL;
        ListNode *next=NULL;
        curr=*head;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        *head=prev;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1=headA;
        ListNode *temp2=headB;
        while(temp1->next!=NULL)
            temp1=temp1->next;
        while(temp2->next!=NULL)
            temp2=temp2->next;
        if(temp1!=temp2)
            return NULL;
        stack<ListNode *>s;
        temp2=headB;
        while(temp2!=NULL)
        {
            s.push(temp2);
            temp2=temp2->next;
        }
        reverse(&headA);
        ListNode *ans=headA;
        while(s.empty()!=true && headA)
        {
            ListNode *temp=s.top();
            s.pop();
            if(temp!=headA)
                return ans;
            headA=headA->next;
            ans=headA;
        }
        return ans;
    }
};