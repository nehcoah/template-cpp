class Solution {
    const int mod = 1e9 + 7;
    vector<vector<int>> f;
    int dfs(int i, int p, vector<int>& nums) {
        if (i == nums.size()) return 1;
        if (f[i][p] != -1) return f[i][p];
        int ans = 0;
        for (int x = p; x <= nums[i]; x++) {
            int y = nums[i] - x;
            int py = nums[i - 1] - p;
            if (py >= y) ans = (ans + dfs(i + 1, x, nums)) % mod;
        }
        return f[i][p] = ans;
    }
public:
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        f.assign(n, vector<int>(mx + 1, -1));
        int ans = 0;
        for (int x = 0; x <= nums[0]; x++) {
            ans = (ans + dfs(1, x, nums)) % mod;
        }
        return ans;
    }
};
