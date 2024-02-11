class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        auto ans = matrix;
        vector<int> mx(ans[0].size(), -1);
        for (int i = 0; i < ans[0].size(); i++) {
            for (int j = 0; j < ans.size(); j++) {
                mx[i] = max(mx[i], ans[j][i]);
            }
        }
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[0].size(); j++) {
                if (ans[i][j] == -1) {
                    ans[i][j] = mx[j];
                }
            }
        }
        return ans;
    }
};
