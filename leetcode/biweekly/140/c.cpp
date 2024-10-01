class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<int> suf(m + 1);
        suf[m] = n;
        for (int i = m - 1, j = n - 1; i >= 0; i--) {
            if (j >= 0 && word1[i] == word2[j]) j -= 1;
            suf[i] = j + 1;
        }

        vector<int> ans(n);
        bool ok = false;
        for (int i = 0, j = 0; i < m; i++) {
            if (word1[i] == word2[j] || (!ok && suf[i + 1] <= j + 1)) {
                if (word1[i] != word2[j]) ok = true;
                ans[j] = i;
                j += 1;
                if (j == n) return ans;
            }
        }
        return {};
    }
};
