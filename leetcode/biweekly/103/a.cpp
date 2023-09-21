// https://leetcode.cn/problems/maximum-sum-with-exactly-k-elements/

class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int ans = 0;
        while (k--){
            int idx = max_element(nums.begin(), nums.end()) - nums.begin();
            ans += nums[idx];
            nums[idx]++;
        }
        return ans;
    }
};
