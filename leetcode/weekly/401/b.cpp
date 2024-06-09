class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        const int mod = 1e9 + 7;
        vector<int> a(n, 1);
        for (int x = 0; x < k; x++) {
            for (int i = 1; i < n; i++) {
                a[i] = (a[i] + a[i - 1]) % mod;
            }
        }
        return a.back();
    }
};
