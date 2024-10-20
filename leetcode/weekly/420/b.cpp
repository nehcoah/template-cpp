class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        vector<int> cnt(26);

        auto check = [&]() {
            return *max_element(cnt.begin(), cnt.end()) >= k;
        };

        int ans = 0;
        for (int i = 0, j = 0; i < s.size(); i++) {
            cnt[s[i] - 'a'] += 1;
            if (check()) {
                while (j < s.size() && check()) {
                    cnt[s[j] - 'a'] -= 1;
                    j += 1;
                }
                cnt[s[j - 1] - 'a'] += 1;
                j -= 1;
                ans += j + 1;
            }
        }
        return ans;
    }
};
