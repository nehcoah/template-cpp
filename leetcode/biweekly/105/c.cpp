// https://leetcode.cn/problems/maximum-strength-of-a-group/

class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long ans = LONG_MIN;
        int n = nums.size();
        function<void(int, long long)> dfs = [&](int i, long long sum){
            if (i == n) {
                ans = max(ans, sum);
                return;
            }
            dfs(i + 1, sum);
            if (i < n - 1) dfs(i + 1, sum * nums[i + 1]);
        };
        for (int j = 0; j < n; j++) dfs(j, nums[j]);
        return ans;
    }
};
