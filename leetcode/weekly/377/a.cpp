class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        ranges::sort(nums);
        for (int i = 0; i < n; i += 2) {
            ans[i] = nums[i + 1];
            ans[i + 1] = nums[i];
        }
        return ans;
    }
};
