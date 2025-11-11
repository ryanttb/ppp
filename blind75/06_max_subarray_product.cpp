class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProdLTR{nums[0]};
        int maxProdRTL{nums[n - 1]};

        for (int curProd{nums[0]}, i{1}; i < n; ++i) {
            int num = nums[i];
            curProd = curProd * num;
            maxProdLTR = max(maxProdLTR, curProd);
            maxProdLTR = max(maxProdLTR, num);
        }

        for (int curProd{nums[n - 1]}, i{n - 2}; i >= 0; --i) {
            int num = nums[i];
            curProd = curProd * num;
            maxProdRTL = max(maxProdRTL, curProd);
            maxProdRTL = max(maxProdRTL, num);
        }

        return max(maxProdLTR, maxProdRTL);
    }
};