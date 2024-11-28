class Solution {
public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();

        vector f(n, vector(op1 + 1, vector<int>(op2 + 1, -1)));
        auto dfs = [&](auto self, int i, int c1, int c2) {
            if (i == n) return 0;
            if (f[i][c1][c2] != -1) return f[i][c1][c2];
            int ans = 1e9;
            ans = min(ans, self(self, i + 1, c1, c2) + nums[i]);
            if (c1) {
                int cur = (nums[i] + 1) / 2;
                ans = min(ans, self(self, i + 1, c1 - 1, c2) + cur);
                if (c2 && cur >= k) {
                    ans = min(ans, self(self, i + 1, c1 - 1, c2 - 1) + cur - k);
                }
            }
            if (c2 && nums[i] >= k) {
                ans = min(ans, self(self, i + 1, c1, c2 - 1) + nums[i] - k);
                if (c1) {
                    ans = min(ans, self(self, i + 1, c1 - 1, c2 - 1) + (nums[i] - k + 1) / 2);
                }
            }
            return f[i][c1][c2] = ans;
        };

        return dfs(dfs, 0, op1, op2);
    }
};
