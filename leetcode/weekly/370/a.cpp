class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int ans = 0, mx = 0, n = grid.size();
        for (int i = 0; i < n; i++) {
            int cur = accumulate(grid[i].begin(), grid[i].end(), 0);
            if (cur > mx) ans = i, mx = cur;
        }
        return ans;
    }
};
