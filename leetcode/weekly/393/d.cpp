class Solution {
    unordered_map<long long, int> f;
    int dfs(int i, int j, int x, vector<int>& nums, vector<int>& andValues) {
        if (i == nums.size()) {
            if (j == andValues.size()) return 0;
            else return 1e9;
        }
        if (j == andValues.size()) return 1e9;
        long long k = (1ll * i << 36) | (1ll * j << 32) | x;
        if (f.count(k)) return f[k];
        x &= nums[i];
        int ans = 1e9;
        if (x == andValues[j]) ans = min(ans, dfs(i + 1, j + 1, -1, nums, andValues) + nums[i]);
        ans = min(ans, dfs(i + 1, j, x, nums, andValues));
        k = (1ll * i << 36) | (1ll * j << 32) | x;
        return f[k] = ans;
    }
public:
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        int ans = dfs(0, 0, -1, nums, andValues);
        return ans == 1e9 ? -1 : ans;
    }
};
