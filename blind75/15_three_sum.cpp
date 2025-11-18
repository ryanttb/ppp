class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;

        for (int i{0}; i < nums.size(); ++i) {
            for (int j{0}; j < nums.size(); ++j) {
                for (int k{0}; k < nums.size(); ++k) {
                    if (i != j && i != k && j != k && 
                            nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> test = {i, j, k};
                        if (!exists(ret, test)) {
                            ret.push_back(test);
                        }
                    }
                }
            }
        }



        return ret;
    }

    /**
     * \brief       Determine if test is in numSums in any combination
     */
    bool exists(const vector<vector<int>>& numSums, const vector<int>& test) const {
        set<int> indexesSeen;

        for (const auto sum : numSums) {
            indexesSeen.insert(sum.begin(), sum.end());
        }

        indexesSeen.insert(test.begin(), test.end());
        return indexesSeen.size() > 3;
    }
};