// https://leetcode.cn/problems/maximum-strictly-increasing-cells-in-a-matrix/

class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        map<int, vector<pair<int, int>>> mp;
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                mp[mat[i][j]].emplace_back(i, j);
            }
        }
        int ans = 0;
        vector<int> row(m), col(n);
        for (auto& [k, v] : mp){
            vector<int> mx;
            for (auto [i, j] : v){
                mx.push_back(max(row[i], col[j]) + 1);
                ans = max(ans, mx.back());
            }
            for (int k = 0; k < v.size(); k++){
                auto [i, j] = v[k];
                row[i] = max(row[i], mx[k]);
                col[j] = max(col[j], mx[k]);
            }
        }
        return ans;
    }
};
