class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> cache;
        for (auto num : nums) {
            if (cache.contains(num)) {
                return true;
            }
            cache.insert(num);
        }
        return false;
    }
};