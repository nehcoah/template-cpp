class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int n = points.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            auto &a = points[i];
            auto &b = points[j];
            return max(abs(a[0]), abs(a[1])) < max(abs(b[0]), abs(b[1]));
        });
        int ans = 0, cur = 0;
        vector<int> cnt(26);
        for (int i = 0; i < n; ) {
            cur = max(abs(points[idx[i]][0]), abs(points[idx[i]][1]));
            bool ok = true;
            while (i < n && max(abs(points[idx[i]][0]), abs(points[idx[i]][1])) == cur) {
                cnt[s[idx[i]] - 'a'] += 1;
                if (cnt[s[idx[i]] - 'a'] == 2) ok = false;
                i += 1;
            }
            if (ok) ans = i;
            else return ans;
        }
        return ans;
    }
};
