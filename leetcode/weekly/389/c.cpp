class Solution {
public:
    int minimumDeletions(string word, int k) {
        array<int, 26> cnt{};
        for (char c : word) {
            cnt[c - 'a'] += 1;
        }
        sort(cnt.begin(), cnt.end());
        int ans = word.size(), i = 0;
        while (cnt[i] == 0) i += 1;
        for (; i < 26; i++) {
            int x = cnt[i];
            int y = cnt[i] + k;
            int cur = 0;
            for (int j = 0; j < 26; j++) {
                if (cnt[j] < x) cur += cnt[j];
                if (cnt[j] > y) cur += cnt[j] - y;
            }
            ans = min(ans, cur);
        }
        return ans;
    }
};
