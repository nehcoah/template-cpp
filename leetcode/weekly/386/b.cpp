class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        
        auto check = [&](int a, int b, int c, int d) {
            if (b <= c || d <= a) return 0;
            else if (a <= c && d <= b) return d - c;
            else if (c <= a && b <= d) return b - a;
            else if (a <= c && b <= d) return b - c;
            else return d - a;
        };
        
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = bottomLeft[i][0], y1 = bottomLeft[i][1];
                int x2 = topRight[i][0], y2 = topRight[i][1];
                int a1 = bottomLeft[j][0], b1 = bottomLeft[j][1];
                int a2 = topRight[j][0], b2 = topRight[j][1];
                int t = min(check(x1, x2, a1, a2), check(y1, y2, b1, b2));
                ans = max(ans, 1ll * t * t);
            }
        }
        return ans;
    }
};
