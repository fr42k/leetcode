// Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....
//
// Example:
//
//
// Input: nums = [3,5,2,1,6,4]
// Output: One possible answer is [3,5,1,6,2,4]
//


class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.size() <= 1) return;
        for (int i = 0, j = 1; j < nums.size(); i++, j++) {
            if (i % 2 && nums[i] < nums[j]) {
                swap(nums[i], nums[j]);
            } else if (!(i % 2) && nums[i] > nums[j]) {
                swap(nums[i], nums[j]);
            }
        }
    }
};
