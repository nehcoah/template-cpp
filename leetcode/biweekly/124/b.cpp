class Solution {
public:
    string lastNonEmptyString(string s) {
        int n = s.size();
        string ans;
        array<int, 26> cnt{}, vis{};
        for (char c : s) {
            cnt[c - 'a']++;
        }
        int mx = *max_element(cnt.begin(), cnt.end());
        for (int i = n - 1; i >= 0; i--) {
            if (cnt[s[i] - 'a'] == mx && vis[s[i] - 'a'] == 0) {
                ans.push_back(s[i]);
                vis[s[i] - 'a'] = 1;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
