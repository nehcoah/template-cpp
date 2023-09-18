// https://leetcode.cn/problems/find-the-value-of-the-partition/

class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = INT_MAX, n = nums.size();
        for (int i = 1; i < n; i++){
            ans = min(ans, nums[i] - nums[i - 1]);
        }
        return ans;
    }
};
