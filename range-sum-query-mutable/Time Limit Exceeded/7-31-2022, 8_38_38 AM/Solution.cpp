// https://leetcode.com/problems/range-sum-query-mutable

class NumArray {
public:
    vector<int>arr;
    int sum=0;
    NumArray(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            arr.push_back(nums[i]);
            sum+=nums[i];
        }
    }
    
    void update(int index, int val) {
        sum+=(val-arr[index]);
        arr[index]=val;
    }
    
    int sumRange(int left, int right) {
        int ans=0;
        for(int i=left;i<=right;i++)
            ans+=arr[i];
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */