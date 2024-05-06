class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.size();
        vector<int> cnt(26);
        for (char c : s) {
            cnt[c - 'a'] += 1;
        }
        
        auto check = [&](int x) {
            for (int i = 0; i < n; i += x) {
                vector<int> cur(26);
                for (int j = 0; j < x; j++) {
                    cur[s[i + j] - 'a'] += 1;
                }
                for (int j = 0; j < 26; j++) {
                    if (cur[j] * (n / x) != cnt[j]) return false;
                }
            }
            return true;
        };
        
        for (int i = 1; i <= n; i++) {
            if (n % i == 0 && check(i)) return i;
        }
        return 0;
    }
};
