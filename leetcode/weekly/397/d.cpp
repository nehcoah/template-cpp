class Solution {
public:
    vector<int> findPermutation(vector<int>& nums) {
        int n = nums.size();
        
        vector f(n, vector<int>(1 << n, -1));
        auto dfs = [&](auto self, int x, int mask) {
            if (mask == (1 << n) - 1) {
                return abs(x - nums[0]);
            }
            if (f[x][mask] != -1) return f[x][mask];
            int ans = 1e9;
            for (int y = 0; y < n; y++) {
                if (mask >> y & 1) continue;
                ans = min(ans, self(self, y, mask | 1 << y) + abs(x - nums[y]));
            }
            return f[x][mask] = ans;
        };
        
        vector<int> ans;
        auto get = [&](auto self, int x, int mask) {
            ans.push_back(x);
            if (mask == (1 << n) - 1) return;
            int t = dfs(dfs, x, mask);
            for (int y = 0; y < n; y++) {
                if (mask >> y & 1) continue;
                if (dfs(dfs, y, mask | 1 << y) + abs(x - nums[y]) == t) {
                    self(self, y, mask | 1 << y);
                    break;
                }
            }
        };
        get(get, 0, 1);
        return ans;
    }
};
