class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<vector<int>> f(n, vector<int>(2));
        (groups[0] == 1 ? f[0][1] : f[0][0]) = 1;
        for (int i = 1; i < n; i++) {
            f[i] = f[i - 1];
            if (groups[i] == 1) f[i][1] = max(f[i][1], f[i - 1][0] + 1);
            else f[i][0] = max(f[i][0], f[i - 1][1] + 1);
        }
        
        int cur = f[n - 1][0] < f[n - 1][1];
        vector<string> ans;
        for (int i = n - 1; i >= 0; i--) {
            if (groups[i] == cur) ans.push_back(words[i]), cur ^= 1;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
