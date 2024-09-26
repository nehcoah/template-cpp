class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        auto check = [&](int l, int r) {
            int cnt = 0;
            for (int i = l; i <= r; i++) {
                cnt += s[i] == '0';
            }
            return cnt <= k || r - l + 1 - cnt <= k;
        };
        
        int ans = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                ans += check(i, j);
            }
        }
        return ans;
    }
};
