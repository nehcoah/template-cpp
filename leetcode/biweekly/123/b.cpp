class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int a = points[i][0], b = points[i][1];
                int c = points[j][0], d = points[j][1];
                if (a <= c && b >= d) {
                    bool good = true;
                    for (int k = 0; k < n; k++) {
                        if (k == i || k == j) continue;
                        int x = points[k][0], y = points[k][1];
                        if (x >= a && x <= c && y >= d && y <= b) {
                            good = false;
                            break;
                        }
                    }
                    ans += good;
                }
            }
        }
        return ans;
    }
};
