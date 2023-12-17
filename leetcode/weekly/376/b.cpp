class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        ranges::sort(nums);
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n; i += 3) {
            if (nums[i + 2] - nums[i] > k) return {};
            else ans.emplace_back(nums.begin() + i, nums.begin() + i + 3);
        }
        return ans;
    }
};
