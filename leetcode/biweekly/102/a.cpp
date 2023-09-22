// https://leetcode.cn/problems/find-the-width-of-columns-of-a-grid/

class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++){
            int mx = 0;
            for (int j = 0; j < m; j++){
                int tmp = to_string(grid[j][i]).size();
                mx = max(mx, tmp);
            }
            ans[i] = mx;
        }
        return ans;
    }
};
