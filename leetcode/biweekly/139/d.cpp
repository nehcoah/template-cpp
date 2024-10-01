class Solution {
public:
    int maxPathLength(vector<vector<int>>& coordinates, int k) {
        int n = coordinates.size();
        int x = coordinates[k][0], y = coordinates[k][1];
        vector<pair<int, int>> a, b;
        for (int i = 0; i < n; i++) {
            int cx = coordinates[i][0], cy = coordinates[i][1];
            if (cx < x && cy < y) b.emplace_back(cx, cy);
            if (cx > x && cy > y) a.emplace_back(cx, cy);
        }
        sort(a.begin(), a.end(), [&](auto &p, auto &q) {
            return p.first == q.first ? p.second > q.second : p.first < q.first;
        });
        sort(b.begin(), b.end(), [&](auto &p, auto &q) {
            return p.first == q.first ? p.second > q.second : p.first < q.first;
        });

        auto check = [&](vector<pair<int, int>> &cur) {
            vector<int> lis;
            for (int i = 0; i < cur.size(); i++) {
                auto it = lower_bound(lis.begin(), lis.end(), cur[i].second);
                if (it == lis.end()) lis.push_back(cur[i].second);
                else *it = cur[i].second;
            }
            return lis.size();
        };

        return check(a) + check(b) + 1;
    }
};
