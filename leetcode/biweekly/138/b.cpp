class Solution {
public:
    string stringHash(string s, int k) {
        int n = s.size();
        string ans;
        for (int i = 0; i < n; i += k) {
            int tot = 0;
            for (int j = 0; j < k; j++) {
                tot += s[i + j] - 'a';
            }
            ans += char(tot % 26 + 'a');
        }
        return ans;
    }
};
