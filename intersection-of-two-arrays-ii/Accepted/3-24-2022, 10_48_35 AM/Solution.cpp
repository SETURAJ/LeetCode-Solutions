// https://leetcode.com/problems/intersection-of-two-arrays-ii

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m;
        for(int i=0;i<nums1.size();i++)
            m[nums1[i]]++;
        vector<int>res;
        for(auto a:nums2)
        {
            if(m[a])
            {
                res.push_back(a);
                m[a]--;
            }
        }
        return res;
    }
};