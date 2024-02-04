class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), [&](auto &x, auto &y) {
            return x[0] == y[0] ? x[1] > y[1] : x[0] < y[0];
        });
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int mx = -1e9 - 1;
            for (int j = i + 1; j < n; j++) {
                if (points[j][1] <= points[i][1] && points[j][1] > mx) {
                    ans += 1;
                    mx = points[j][1];
                }
            }
        }
        return ans;
    }
};
