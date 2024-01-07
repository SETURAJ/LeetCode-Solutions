// https://leetcode.com/problems/arithmetic-subarrays

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        vector<bool> res(l.size(),false);
        
        for(int i=0;i<l.size();i++)
        {
            vector<int>arr=nums;
            bool change = true;
            int start = l[i];
            int end = r[i];
            if(abs(start-end)<1)
                res[i]=false;
            else if(abs(start-end)==1)
                res[i]=true;
            else
            {   
                sort(arr.begin()+start,arr.begin()+end+1);
                int diff = arr[start+1]-arr[start];
                for(int j=start;j<end;j++)
                {
                    if(arr[j+1]-arr[j]!=diff)
                        change=false;
                }
                if(change)
                    res[i]=true;
            }
            
        }
        return res;
    }
};