// https://leetcode.com/problems/video-stitching

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(),clips.end());
        int res=0;
        int i=0,maxReach=0;
        while(maxReach<time)
        {
            int curr=0;
            while(i<clips.size() && clips[i][0]<=maxReach)
                curr=max(curr,clips[i++][1]);
            if(curr<=maxReach)
                return -1;
            maxReach=curr;
            res++;
        }
        return res;
    }
};