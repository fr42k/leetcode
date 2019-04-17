// Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.
//
// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
//
// Note: You are not suppose to use the library's sort function for this problem.
//
// Example:
//
//
// Input: [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
//
// Follow up:
//
//
// 	A rather straight forward solution is a two-pass algorithm using counting sort.
// 	First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
// 	Could you come up with a one-pass algorithm using only constant space?
//
//


class Solution {
public:
    void sortColors(vector<int>& nums) {
        myqsort(nums, 0, nums.size() - 1);
    }
    
private:
    void myqsort(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return;
        }
        int p = partition(nums, l, r);
        myqsort(nums, l, p - 1);
        myqsort(nums, p + 1, r);
    }
    int partition(vector<int>& nums, int a, int b) {
        int pivot = nums[a];
        while (a < b) {
            while (a < b && nums[b] >= pivot) {
                b--;
            }
            nums[a] = nums[b];
            while (a < b && nums[a] <= pivot) {
                a++;
            }
            nums[b] = nums[a];
        }
        nums[a] = pivot;
        return a;
    }
};
