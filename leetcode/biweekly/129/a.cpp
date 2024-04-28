class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        vector a(3, vector<int>(3));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                a[i][j] = grid[i][j] == 'B';
            }
        }
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                int sum = a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1];
                if (sum != 2) return true;
            }
        }
        return false;
    }
};
