class Solution {
public:
    int maxRectangleArea(vector<vector<int>>& points) {
        int n = points.size();
        auto check = [&](int a, int b, int c, int d) {
            int x1 = points[a][0], y1 = points[a][1];
            int x2 = points[b][0], y2 = points[b][1];
            int x3 = points[c][0], y3 = points[c][1];
            int x4 = points[d][0], y4 = points[d][1];
            vector<int> x{x1, x2, x3, x4};
            vector<int> y{y1, y2, y3, y4};
            sort(x.begin(), x.end());
            sort(y.begin(), y.end());
            if (x[0] == x[1] && x[1] != x[2] && x[2] == x[3]) {
                if (y[0] == y[1] && y[1] != y[2] && y[2] == y[3]) {
                    for (int i = 0; i < n; i++) {
                        if (i == a || i == b || i == c || i == d) continue;
                        if (points[i][0] >= x[0] && points[i][0] <= x[3] && points[i][1] >= y[0] && points[i][1] <= y[3]) {
                            return -1;
                        }
                    }
                    return (x[3] - x[0]) * (y[3] - y[0]);
                } else {
                    return -1;
                }
            } else {
                return -1;
            }
        };

        int ans = -1;
        for (int a = 0; a < n; a++) {
            for (int b = a + 1; b < n; b++) {
                for (int c = b + 1; c < n; c++) {
                    for (int d = c + 1; d < n; d++) {
                        ans = max(ans, check(a, b, c, d));
                    }
                }
            }
        }
        return ans;
    }
};
