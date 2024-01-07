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
   
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1=headA;
        ListNode *temp2=headB;
        stack<ListNode*>s1,s2;
        while(temp1!=NULL)
        {
            s1.push(temp1);
            temp1=temp1->next;
        }
        while(temp2!=NULL)
        {
            s2.push(temp2);
            temp2=temp2->next;
        }
        if(temp1!=temp2)
            return NULL;
        ListNode *prev=NULL,*a,*b;
        while(!s1.empty() && !s2.empty())
        {
            a=s1.top();
            s1.pop();
            b=s2.top();
            s2.pop();
            if(a==b)
                prev=a;
            else
                return prev;
        }
        return prev;
        
    }
};