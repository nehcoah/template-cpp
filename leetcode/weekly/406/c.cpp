class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        vector<pair<int, int>> a;
        for (int i = 0; i < m - 1; i++) {
            a.emplace_back(i, 0);
        }
        for (int i = 0; i < n - 1; i++) {
            a.emplace_back(i, 1);
        }
        sort(a.begin(), a.end(), [&](auto x, auto y) {
            return (x.second == 0 ? horizontalCut[x.first] : verticalCut[x.first]) > (y.second == 0 ? horizontalCut[y.first] : verticalCut[y.first]);
        });
        
        int ans = 0;
        int r = 1, c = 1;
        for (auto [i, p] : a) {
            if (p == 0) ans += r * horizontalCut[i], c = min(m, c + 1);
            else ans += c * verticalCut[i], r = min(n, r + 1);
        }
        return ans;
    }
};
