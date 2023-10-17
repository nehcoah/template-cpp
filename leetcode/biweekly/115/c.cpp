class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        int dis[n][n];
        for (int i = 0; i < n; i++) {
            dis[i][i] = 0;
            for (int j = i + 1; j < n; j++) {
                string s1 = words[i], s2 = words[j];
                if (s1.size() != s2.size()) dis[i][j] = dis[j][i] = -1;
                else {
                    int cnt = 0;
                    for (int i = 0; i < s1.size(); i++) if (s1[i] != s2[i]) cnt++;
                    dis[i][j] = dis[j][i] = cnt;
                }
            }
        }
        
        vector<pair<int, int>> f(n);
        for (int i = 0; i < n; i++) {
            f[i] = {1, -1};
            for (int j = 0; j < i; j++) {
                if (dis[i][j] != 1 || groups[i] == groups[j]) continue;
                if (f[j].first + 1 > f[i].first) f[i] = {f[j].first + 1, j};
            }
        }
        int ans = 0, idx = -1;
        for (int i = 0; i < n; i++) {
            if (ans < f[i].first) ans = f[i].first, idx = i;
        }
        
        vector<string> res;
        for (int i = idx; i != -1; i = f[i].second) {
            res.push_back(words[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
