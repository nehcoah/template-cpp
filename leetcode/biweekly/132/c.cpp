class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector f(n, vector<int>(k + 1, -1));
        auto dfs = [&](auto self, int i, int cnt) {
            if (i == n) return 0;
            if (f[i][cnt] != -1) return f[i][cnt];
            int ans = 0;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] == nums[i]) ans = max(ans, self(self, j, cnt) + 1);
                else if (cnt < k) ans = max(ans, self(self, j, cnt + 1) + 1);
            }
            return f[i][cnt] = ans;
        };
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(dfs, i, 0) + 1);
        }
        return ans;
    }
};
