class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Kadane's algorithm
        int maxSum{nums[0]};
        int curSum{nums[0]};

        for (int i{1}; i < nums.size(); ++i) {
            int num = nums[i];
            curSum = max(num, curSum + num);
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};