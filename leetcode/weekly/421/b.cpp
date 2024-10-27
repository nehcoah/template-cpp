class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int mod = 1e9 + 7;
        vector<int> cnt(26);
        for (char c : s) {
            cnt[c - 'a'] += 1;
        }
        for (int i = 0; i < t; i++) {
            vector<int> nxt(26);
            for (int j = 0; j < 25; j++) {
                nxt[j + 1] = cnt[j];
            }
            nxt[0] = cnt[25];
            nxt[1] = (nxt[1] + cnt[25]) % mod;
            cnt.swap(nxt);
        }
        int ans = 0;
        for (int x : cnt) {
            ans = (ans + x) % mod;
        }
        return ans;
    }
};
