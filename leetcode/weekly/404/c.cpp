class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector f(k, vector<pair<int, int>>(k, {-1, -1}));
        for (int i = 0; i < n; i++) {
            int x = nums[i] % k;
            for (int j = 0; j < k; j++) {
                auto [p, c] = f[x][j];
                if (p == -1) f[x][j] = f[j][x] = {j, 1};
                else if (p == x) {
                    f[x][j] = f[j][x] = {j, c + 1};
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < k; i++) {
            for (int j = i; j < k; j++) {
                ans = max(ans, f[i][j].second);
            }
        }
        return ans;
    }
};
