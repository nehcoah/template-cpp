class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int mn = 1e9 + 1, mx = -1e9 - 1, mni = -1, mxi = -1, n = nums.size();
        for (int i = indexDifference; i < n; i++) {
            int pre = i - indexDifference;
            if (mx < nums[pre]) {
                mx = nums[pre];
                mxi = pre;
            }
            if (mn > nums[pre]) {
                mn = nums[pre];
                mni = pre;
            }
            if (nums[i] - mn >= valueDifference) return {mni, i};
            if (mx - nums[i] >= valueDifference) return {mxi, i};
        }
        return {-1, -1};
    }
};
