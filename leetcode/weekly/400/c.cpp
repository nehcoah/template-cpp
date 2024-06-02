class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        vector<int> vis(n);
        vector<vector<int>> cnt(26);
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                for (int i = 0; i < 26; i++) {
                    if (!cnt[i].empty()) {
                        vis[cnt[i].back()] = 1;
                        cnt[i].pop_back();
                        break;
                    }
                }
            } else {
                cnt[s[i] - 'a'].push_back(i);
            }
        }
        string ans;
        for (int i = 0; i < n; i++) {
            if (s[i] != '*' && !vis[i]) ans += s[i];
        }
        return ans;
    }
};
