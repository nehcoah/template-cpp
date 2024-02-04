class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int m = image.size(), n = image[0].size();
        vector ans(m, vector<int>(n));
        vector cnt(m, vector<int>(n));
        
        auto check = [&](int x, int y) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 2; j++) {
                    if (abs(image[x + i][y + j] - image[x + i][y + j + 1]) > threshold) return -1;
                }
            }
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 3; j++) {
                    if (abs(image[x + i][y + j] - image[x + i + 1][y + j]) > threshold) return -1;
                }
            }
            int sum = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    sum += image[x + i][y + j];
                }
            }
            return sum;
        };
        
        for (int i = 0; i < m - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                int x = check(i, j);
                if (x == -1) continue;
                x /= 9;
                for (int di = 0; di < 3; di++) {
                    for (int dj = 0; dj < 3; dj++) {
                        ans[i + di][j + dj] += x;
                        cnt[i + di][j + dj]++;
                    }
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (cnt[i][j] == 0) ans[i][j] = image[i][j];
                else ans[i][j] /= cnt[i][j];
            }
        }
        return ans;
    }
};
