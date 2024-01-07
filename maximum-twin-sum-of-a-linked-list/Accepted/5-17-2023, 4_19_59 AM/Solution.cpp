// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list

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
    int pairSum(ListNode* head) {
        ListNode* curr=head;
        vector<int>vals;
        while(curr)
        {
            vals.push_back(curr->val);
            curr=curr->next;
        }
        int i=0,j=vals.size()-1;
        int res=0;
        while(i<j)
        {
            res=max(res,vals[i]+vals[j]);
            i++;
            j--;
        }
        return res;
    }
};