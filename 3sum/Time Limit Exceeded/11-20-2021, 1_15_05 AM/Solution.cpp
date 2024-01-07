// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>res;
        for(int i=0;i<n-2;i++)
        {
            int l=i+1;
            int r=n-1;
            while(l<r)
            {
                if(nums[i]+nums[l]+nums[r]==0)
                {
                    vector<int>temp(3);
                    temp[0]=nums[i];
                    temp[1]=nums[l];
                    temp[2]=nums[r];
                    
                    sort(temp.begin(),temp.end());
                    res.push_back(temp);
                    l++;
                    r--;
                }
                else if(nums[i]+nums[l]+nums[r]<0)
                    l++;
                else
                    r--;
            }
        }
        set<vector<int>>st;
        for(auto it:res)
            st.insert(it);
        vector<vector<int>>answer;
        for(auto it:st)
            answer.push_back(it);
        return answer;
    }
};