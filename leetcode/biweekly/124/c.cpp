class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        
        vector f(n, vector<int>(n, -1));
        auto dfs = [&](auto self, int i, int j, int sum) {
            if (i >= j) return 0;
            if (f[i][j] != -1) return f[i][j];
            int ans = 0;
            if (nums[i] + nums[i + 1] == sum) ans = max(ans, self(self, i + 2, j, sum) + 1);
            if (nums[j] + nums[j - 1] == sum) ans = max(ans, self(self, i, j - 2, sum) + 1);
            if (nums[i] + nums[j] == sum) ans = max(ans, self(self, i + 1, j - 1, sum) + 1);
            return f[i][j] = ans;
        };
        
        int ans = dfs(dfs, 0, n - 3, nums[n - 1] + nums[n - 2]) + 1;
        f.assign(n, vector<int>(n, -1));
        ans = max(ans, dfs(dfs, 1, n - 2, nums[n - 1] + nums[0]) + 1);
        f.assign(n, vector<int>(n, -1));
        ans = max(ans, dfs(dfs, 2, n - 1, nums[1] + nums[0]) + 1);
        return ans;
    }
};
