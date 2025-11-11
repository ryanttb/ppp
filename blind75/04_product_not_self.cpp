class Solution {
public:
    vector<int> productExceptSelfWithDivide(vector<int>& nums) {
        vector<int> answer(nums.size());
        int product = reduce(nums.begin(), nums.end(), 1, multiplies<>());
        size_t i{0};
        for (auto num : nums) {            
            answer[i] = product / (num == 0 ? 1 : num);
            ++i;
        }
        cout << "product: " << product << endl;
        return answer;
    }

    vector<int> productExceptSelfWithoutDivide(vector<int>& nums) {
        int n = nums.size();

        vector<int> answer(n);

        vector<int> prefix(n);
        vector<int> suffix(n);

        prefix[0] = 1;
        for (int i{1}; i < n; ++i) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        suffix[n - 1] = 1;
        for (int j{n - 2}; j >= 0; --j) {
            suffix[j] = suffix[j + 1] * nums[j + 1];
        }
        
        for (int k{0}; k < n; ++k) {
            answer[k] = prefix[k] * suffix[k];
        }
        return answer;
    }
};