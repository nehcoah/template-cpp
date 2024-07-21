class Solution {
public:
    int minimumLength(string s) {
        vector<int> cnt(26);
        for (char c : s) {
            cnt[c - 'a'] += 1;
        }
        int ans = 0;
        for (int x : cnt) {
            if (x) ans += x % 2 ? 1 : 2;
        }
        return ans;
    }
};
