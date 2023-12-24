class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int r = n - 2;
        while (r >= 0 && nums[r] < nums[r + 1]) r--;
        if (r == -1) return n * (n + 1) / 2;
        int ans = n - r;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] <= nums[i - 1]) break;
            int x = upper_bound(nums.begin() + r + 1, nums.end(), nums[i]) - nums.begin();
            ans += n - x + (i <= r);
        }
        return ans;
    }
};
