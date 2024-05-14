class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        int n = s.size();
        
        auto sub = [&](vector<int> &b, vector<int> &a) {
            int p = -1;
            for (int i = 0; i < 26; i++) {
                int c = b[i] - a[i];
                if (c == 0) continue;
                if (p == -1) p = c;
                else if (p != c) return false;
            }
            return true;
        };
        
        vector<vector<int>> cnt(n + 1, vector<int>(26));
        for (int i = 0; i < n; i++) {
            cnt[i + 1] = cnt[i];
            cnt[i + 1][s[i] - 'a'] += 1;
        }
        
        int f[n + 1];
        for (int i = 0; i < n + 1; i++) f[i] = 1e9;
        f[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                if (sub(cnt[i + 1], cnt[j])) {
                    f[i + 1] = min(f[i + 1], f[j] + 1);
                }
            }
        }
        return f[n];
    }
};
