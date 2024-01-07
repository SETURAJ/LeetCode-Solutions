// https://leetcode.com/problems/insert-interval

class Solution {
public:
    
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       vector<vector<int>> ans;
    ans.reserve(intervals.size() + 1);
    for (auto &interval : intervals) {
      if (interval[0] <= newInterval[0]) {
        ans.push_back(interval);
      } else {
        break;
      }
    }
    if (ans.empty() || ans.back()[1] < newInterval[0]) {
      ans.push_back(newInterval);
    } else {
      ans.back()[1] = max(ans.back()[1], newInterval[1]);
    }
    for (auto &interval : intervals) {
      if (interval[0] <= newInterval[0]) {
        continue;
      }
      if (ans.back()[1] >= interval[0]) {
        ans.back()[1] = max(ans.back()[1], interval[1]);
      } else {
        ans.push_back(interval);
      }
    }
    return ans;
        
    }
};