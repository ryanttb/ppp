class Solution {
public:
    int findMin(vector<int>& nums) {
        return findMinBinary(nums);
    }

    int findMinBinary(vector<int>& nums) {
        int n = nums.size();
        cout << "n: " << n << endl;

        if (n == 1) {
            return nums[0];
        } else if (n == 2) {
            return min(nums[0], nums[1]);
        }

        int leftIdx{0};
        int rightIdx = nums.size() - 1;

        bool found{false};

        while (!found) {
            int curIdx = leftIdx + (rightIdx - leftIdx)/2;
            cout << "leftIdx: " << leftIdx << ", rightIdx: " << rightIdx << ", curIdx: " << curIdx << endl;

            if (leftIdx == rightIdx) {
                return nums[curIdx];
            } else if (rightIdx - leftIdx == 1) {
                return min(nums[leftIdx], nums[rightIdx]);
            }

            if (nums[curIdx - 1] > nums[curIdx] && nums[curIdx + 1] > nums[curIdx]) {
                // found inflection point
                return nums[curIdx];
            }

            if (nums[curIdx] < nums[rightIdx]) {
                rightIdx = curIdx ;
                continue;
            }

            if (nums[curIdx] > nums[rightIdx]) {
                leftIdx = curIdx + 1;
                continue;
            }

            cout << "found: false";
            break; // just in case
        }
        
        return nums[0];
    }

    int findMinLeftRight(vector<int>& nums) {
        int n = nums.size();
        cout << "n: " << n << endl;

        int leftIdx{0};
        int rightIdx{n - 1};

        int rotated{0};

        for (int i{0}; i < n; ++i) {
            int left = nums[leftIdx + i];
            int right = nums[rightIdx - i];

            cout << "left: " << left << ", right: " << right << endl;

            if (left > right) {
                ++rotated;
            } else {
                break;
            }
        }
        cout << "rotated: " << rotated << endl;
        if (rotated == 0) {
            return nums[0];
        } else {
            return nums[n - rotated];
        }
    }
};