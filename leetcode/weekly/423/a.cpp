class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        auto check = [&](int l, int r) {
            for (int i = l + 1; i < r; i++) {
                if (nums[i] <= nums[i - 1]) {
                    return false;
                }
            }
            return true;
        };

        int n = nums.size();
        for (int i = 0; i + 2 * k <= n; i++) {
            if (check(i, i + k) && check(i + k, i + 2 * k)) {
                return true;
            }
        }
        return false;
    }
};
