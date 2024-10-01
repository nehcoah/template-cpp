class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int n = word1.size();
        vector<int> cnt(26);
        for (char c : word2) {
            cnt[c - 'a'] -= 1;
        }
        int tot = count_if(cnt.begin(), cnt.end(), [&](int x) {
            return x < 0;
        });

        long long ans = 0;
        for (int l = 0, r = 0; l < n; l++) {
            while (r < n && tot) {
                cnt[word1[r] - 'a'] += 1;
                if (cnt[word1[r] - 'a'] == 0) tot -= 1;
                r += 1;
            }
            if (tot == 0) ans += n - r + 1;
            if (cnt[word1[l] - 'a'] == 0) tot += 1;
            cnt[word1[l] - 'a'] -= 1;
        }
        return ans;
    }
};
