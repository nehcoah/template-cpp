class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> cnt(26);
        int ans = 0, n = s.size();
        for (int i = 0, j = 0; i < n; i++) {
            cnt[s[i] - 'a'] += 1;
            while (cnt[s[i] - 'a'] > 2) {
                cnt[s[j] - 'a'] -= 1;
                j += 1;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
