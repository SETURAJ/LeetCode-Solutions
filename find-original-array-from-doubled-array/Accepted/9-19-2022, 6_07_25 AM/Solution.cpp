// https://leetcode.com/problems/find-original-array-from-doubled-array

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n=changed.size();
        sort(changed.begin(),changed.end());
        if(n%2==1)
            return {};
        vector<int>ans;
        map<int,int>mp;
        for(auto i:changed)
            mp[i]++;
        for(int i=0;i<n;i++)
        {
            if(mp[changed[i]]==0)
                continue;
            if(mp[changed[i]*2]==0)
                return {};
            ans.push_back(changed[i]);
            mp[changed[i]]--;
            mp[changed[i]*2]--;
        }
        return ans;
    }
};