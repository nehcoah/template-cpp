class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        int mod = 1e9 + 7;
        unordered_set<long long> h{m - 1};
        for (int x : hFences) {
            h.insert(x - 1);
            h.insert(m - x);
        }
        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                h.insert(abs(hFences[j] - hFences[i]));
            }
        }
        long long ans = -1;
        if (h.count(n - 1)) ans = max(ans, (long long)(n - 1) * (n - 1));
        for (int x : vFences) {
            if (h.count(x - 1)) ans = max(ans, (long long)(x - 1) * (x - 1));
            if (h.count(n - x)) ans = max(ans, (long long)(n - x) * (n - x));
        }
        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                long long cur = abs(vFences[j] - vFences[i]);
                if (h.count(cur)) ans = max(ans, cur * cur);
            }
        }
        return ans == -1 ? -1 : ans % mod;
    }
};
