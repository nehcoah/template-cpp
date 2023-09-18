// https://leetcode.cn/problems/difference-of-number-of-distinct-values-on-diagonals/

class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                unordered_set<int> s1, s2;
                for (int x = i - 1, y = j - 1; x >= 0 && y >= 0; x--, y--) s1.insert(grid[x][y]);
                for (int x = i + 1, y = j + 1; x < m && y < n; x++, y++) s2.insert(grid[x][y]);
                ans[i][j] = abs((int)s1.size() - (int)s2.size());
            }
        }
        return ans;
    }
};
