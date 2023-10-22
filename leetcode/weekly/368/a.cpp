class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> suf(n, nums.back());
        for (int i = n - 3; i >= 0; i--) {
            suf[i] = min(nums[i + 1], suf[i + 1]);
        }
        int ans = 1e9 + 1, pre = nums[0];
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > pre && nums[i] > suf[i]) ans = min(ans, nums[i] + pre + suf[i]);
            pre = min(pre, nums[i]);
        }
        return ans != 1e9 + 1 ? ans : -1;
    }
};
