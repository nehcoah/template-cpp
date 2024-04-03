class Solution {
    int cal(const pair<int, int> &a, const pair<int, int> &b) {
        return abs(a.first - b.first) + abs(a.second - b.second);
    }
public:
    int minimumDistance(vector<vector<int>>& points) {
        multiset<pair<int, int>> st;
        for (auto &p : points) {
            st.emplace(p[0], p[1]);
        }
        vector<pair<int, int>> p;
        
        auto check = [&]() {
            auto x = vector(st.begin(), st.end()), y = x;
            sort(x.begin(), x.end(), [&](auto &a, auto &b) {
                return a.first - a.second < b.first - b.second;
            });
            sort(y.begin(), y.end(), [&](auto &a, auto &b) {
                return a.first + a.second < b.first + b.second;
            });
            if (p.empty()) p = vector<pair<int, int>>{x[0], x.back(), y[0], y.back()};
            return max(x.back().first - x.back().second - x[0].first + x[0].second, 
                       y.back().first + y.back().second - y[0].first - y[0].second);
        };
        
        int ans = check();
        for (auto c : p) {
            st.extract(c);
            ans = min(ans, check());
            st.insert(c);
        }
        return ans;
    }
};
