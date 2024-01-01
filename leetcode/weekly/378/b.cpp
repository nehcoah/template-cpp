class Solution {
public:
    int maximumLength(string s) {
        int n = s.size(), mx = 0;
        vector<vector<int>> cnt(26);
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            cnt[s[i] - 'a'].push_back(j - i);
            mx = max(mx, j - i);
            i = j;
        }
        for (int ans = mx; ans >= mx - 2 && ans > 0; ans--) {
            for (int i = 0; i < 26; i++) {
                int cur = 0;
                for (int x : cnt[i]) {
                    if (x == ans) cur++;
                    else if (x == ans + 1) cur += 2;
                    else if (x == ans + 2) cur += 3;
                }
                if (cur >= 3) return ans;
            }
        }
        return -1;
    }
};
