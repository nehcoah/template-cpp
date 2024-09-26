class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while (k--) {
            int p = min_element(nums.begin(), nums.end()) - nums.begin();
            nums[p] *= multiplier;
        }
        return nums;
    }
};
