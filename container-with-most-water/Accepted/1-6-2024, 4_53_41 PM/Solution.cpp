// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int right = height.size()-1;
        int left = 0;
        while(left<right)
        {
            int ht = min(height[left],height[right]);
            area = max(area,(right-left)*ht);
            if(height[left]>height[right])
                right--;
            else
                left++;
        }
        return area;
    }
};