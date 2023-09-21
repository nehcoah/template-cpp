// https://leetcode.cn/problems/maximum-number-of-fish-in-a-grid/

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int parent[m * n];
        int cnt[m * n];
        iota(parent, parent + n * m, 0);
        memset(cnt, 0, sizeof(cnt));
        
        function<int(int)> find = [&](int i){
            if (parent[i] != i) {
                parent[i] = find(parent[i]);
            }
            return parent[i];
        };
        
        function<void(int, int)> uni = [&](int i, int j){
            int x = find(i), y = find(j);
            if (x == y) return;
            parent[y] = x;
            cnt[x] += cnt[y];
        };
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 0) continue;
                cnt[i * n + j] = grid[i][j];
                if (i != 0 && grid[i - 1][j] != 0) uni(i * n + j, (i - 1) * n + j);
                if (j != 0 && grid[i][j - 1] != 0) uni(i * n + j, i * n + j - 1);
            }
        }
        return *max_element(cnt, cnt + m * n);
    }
};
