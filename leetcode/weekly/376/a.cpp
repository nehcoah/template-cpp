class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> cnt(n * n + 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cnt[grid[i][j]]++;
            }
        }
        vector<int> ans(2);
        for (int i = 1; i <= n * n; i++) {
            if (cnt[i] == 2) ans[0] = i;
            if (cnt[i] == 0) ans[1] = i;
        }
        return ans;
    }
};
