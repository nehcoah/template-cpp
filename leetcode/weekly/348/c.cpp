// https://leetcode.cn/problems/sum-of-matrix-after-queries/

class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long ans = 0;
        unordered_set<int> row, col;
        int qn = queries.size();
        for (int i = qn - 1; i >= 0; i--) {
            int t = queries[i][0], idx = queries[i][1], val = queries[i][2];
            if (t == 0) {
                if (row.count(idx)) continue;
                ans += val * (n - col.size());
                row.insert(idx);
            } else {
                if (col.count(idx)) continue;
                ans += val * (n - row.size());
                col.insert(idx);
            }
        }
        return ans;
    }
};
