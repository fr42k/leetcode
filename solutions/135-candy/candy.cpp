// There are N children standing in a line. Each child is assigned a rating value.
//
// You are giving candies to these children subjected to the following requirements:
//
//
// 	Each child must have at least one candy.
// 	Children with a higher rating get more candies than their neighbors.
//
//
// What is the minimum candies you must give?
//
// Example 1:
//
//
// Input: [1,0,2]
// Output: 5
// Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
//
//
// Example 2:
//
//
// Input: [1,2,2]
// Output: 4
// Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
//              The third child gets 1 candy because it satisfies the above two conditions.
//
//


class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n <= 1) return n;
        int i = 0, idx = 0, sum = 1;
        while (i + 1 < n) {
            while (i + 1 < n && ratings[i] < ratings[i + 1]) {
                i++;
            }
            int left = i - idx;
            idx = i;
            while (i + 1 < n && ratings[i] > ratings[i + 1]) {
                i++;
            }
            int right = i - idx;
            idx = i;
            int peak = max(left, right) + 1;
            sum += (1 + left) * left / 2 + peak + (1 + right) * right / 2 - 1;
            while (i + 1 < n && ratings[i] == ratings[i + 1]) {
                i++;
                sum++;
            }
            idx = i;
        }
        return sum;
    }
};
