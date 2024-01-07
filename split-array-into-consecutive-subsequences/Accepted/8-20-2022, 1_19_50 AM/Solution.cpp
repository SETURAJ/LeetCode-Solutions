// https://leetcode.com/problems/split-array-into-consecutive-subsequences

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>cnt,tail;
        for(auto &i:nums)
            cnt[i]++;
        for(auto &i:nums)
        {
            if(!cnt[i])
                continue;
            cnt[i]--;
            if(tail[i-1]>0)
            {
                tail[i-1]--;
                tail[i]++;
            }
            else if(cnt[i+1]&&cnt[i+2])
            {
                cnt[i+1]--;
                cnt[i+2]--;
                tail[i+2]++;
            }
            else return false;
        }
        return true;
    }
};