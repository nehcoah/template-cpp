class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end());
        int ans = 1;
        for (int pre = points[0][0], i = 0; i < points.size(); i++) {
            if (points[i][0] - pre > w) {
                ans += 1;
                pre = points[i][0];
            }
        }
        return ans;
    }
};
