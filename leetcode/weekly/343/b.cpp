// https://leetcode.cn/problems/first-completely-painted-row-or-column/

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<pair<int, int>> idx(m * n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                idx[mat[i][j] - 1] = {i, j};
            }
        }
        int row[m], col[n];
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        for (int i = 0; i < arr.size(); i++) {
            auto [x, y] = idx[arr[i] - 1];
            row[x]++;
            col[y]++;
            if (row[x] == n || col[y] == m) return i;
        }
        return -1;
    }
};
