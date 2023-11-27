class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int ans = 0, n = s.size();
        auto check = [&](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        for (int i = 0; i < n; i++) {
            int v = 0, c = 0;
            for (int j = i; j < n; j++) {
                if (check(s[j])) v++;
                else c++;
                if (v == c && (v * c) % k == 0) ans++;
            }
        }
        return ans;
    }
};
