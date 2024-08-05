class neighborSum {
    int n;
    vector<vector<int>> a;
    vector<pair<int, int>> p;
    int s[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}, t[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
public:
    neighborSum(vector<vector<int>>& grid) {
        a = grid;
        n = a.size();
        p.resize(n * n + 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                p[a[i][j]] = {i, j};
            }
        }
    }
    
    int adjacentSum(int value) {
        auto [x, y] = p[value];
        int ans = 0;
        for (auto &d : s) {
            int nx = x + d[0], ny = y + d[1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                ans += a[nx][ny];
            }
        }
        return ans;
    }
    
    int diagonalSum(int value) {
        auto [x, y] = p[value];
        int ans = 0;
        for (auto &d : t) {
            int nx = x + d[0], ny = y + d[1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                ans += a[nx][ny];
            }
        }
        return ans;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
