class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        bool good = true;
        int n = mat[0].size();
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                if (j % 2 == 0) {
                    if (mat[i][j] != mat[i][((j - k) % n + n) % n]) good = false;
                } else {
                    if (mat[i][j] != mat[i][(j + k) % n]) good = false;
                }
            }
        }
        return good;
    }
};
