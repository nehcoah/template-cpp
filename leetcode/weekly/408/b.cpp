vector<int> p;
auto init = []() {
    int n = 1e5;
    vector<int> a(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        if (!a[i]) continue;
        p.push_back(i);
        for (int j = i + i; j <= n; j += i) {
            a[j] = false;
        }
    }
    return 0;
}();

class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int ans = r - l + 1;
        for (int x : p) {
            if (1ll * x * x > r) break;
            if (1ll * x * x >= l) ans -= 1;
        }
        return ans;
    }
};
