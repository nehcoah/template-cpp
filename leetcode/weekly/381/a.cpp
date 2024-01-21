class Solution {
public:
    int minimumPushes(string word) {
        array<int, 26> cnt{};
        for (char c : word) {
            cnt[c - 'a']++;
        }
        ranges::sort(cnt, greater<>());
        int ans = 0;
        for (int i = 0, c = 0; i < 26; i++, c++) {
            ans += cnt[i] * (c / 8 + 1);
        }
        return ans;
    }
};
