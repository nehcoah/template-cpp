// 2850
// https://leetcode.cn/problems/minimum-moves-to-spread-stones-over-grid/description/
// brute force

class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        vector<vector<int>> cnt;
        vector<int> num;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] > 1) {
                    cnt.push_back(vector<int>());
                    num.push_back(grid[i][j]);
                    for (int x = 0; x < 3; x++) {
                        for (int y = 0; y < 3; y++) {
                            if (grid[x][y] == 0) cnt.back().push_back(abs(x - i) + abs(y - j));
                        }
                    }
                }
            }
        }
        int ans = 100;
        
        auto dfs = [&](auto self, int i) {
            if (i == cnt[0].size()) {
                return 0;
            }
            int ans = 100;
            for (int j = 0; j < num.size(); j++) {
                if (num[j] < 2) continue;
                num[j]--;
                ans = min(ans, self(self, i + 1) + cnt[j][i]);
                num[j]++;
            }
            return ans;
        };
        
        return dfs(dfs, 0);
    }
};
