class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<vector<int>> f(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            f[i][i] = nums[i];
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 0, j = len - 1; j < n; i++, j++) {
                f[i][j] = f[i][j - 1] ^ f[i + 1][j];
            }
        }
        
        vector<vector<int>> g(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            g[i][i] = nums[i];
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 0, j = len - 1; j < n; i++, j++) {
                g[i][j] = max({f[i][j], g[i][j - 1], g[i + 1][j]});
            }
        }
        
        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            ans.push_back(g[l][r]);
        }
        return ans;
    }
};
