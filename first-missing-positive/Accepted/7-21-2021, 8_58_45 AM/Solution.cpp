// https://leetcode.com/problems/first-missing-positive

class Solution {
public:
// we can also use method where we first move all non-positive elements to left
// But, this method makes things more easy as we will have our answer in range [1, nums.size()+1]
    int firstMissingPositive(vector<int>& nums) {
	// first of all, make all -ve numbers and zeroes as some +ve value but that should be greater than nums.size()
	// because we are going to use these (elements-1) as index to mark the presence of corresponding element
        for(int i=0;i<nums.size();i++){
			if(nums[i]<=0)nums[i]=nums.size()+1;
		}
        
		// mark the presence of each element if it is between 1 to nums.size()
        for(int i=0;i<nums.size();i++){
			//since we are marking presence of an element by making element of its corresponding index as -ve
			// therefore, we need to take +ve value or actual value of that element (as it may have been made -ve during process)
			int element=abs(nums[i]);
			// now, presence of each element is marked at an index less by 1 than that element
			// eg. presence of 1 is marked at index 0
			// i.e. if 1 is present, we will make element at index 0 as -ve
            int index=element-1;;
            if(index<nums.size() && nums[index]>0)nums[index]*=(-1);
        }
        
		// finally, index that is still having +ve value means that no element marked it
		// i.e. that index+1 element is not present in the array
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)return i+1;
        }
		// & if all elements from 1 to nums.size() are present, then first missing positive integer is  nums.size()+1
        return nums.size()+1;
    }
};