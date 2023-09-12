// 2842
// https://leetcode.cn/problems/count-k-subsequences-of-a-string-with-maximum-beauty/description/
// string, combination

class Solution {
    const int mod = 1e9 + 7;
    long long C(int n, int m){
        long long ans = 1;
        for (int i = n - m + 1, j = 1; j <= m; i++, j++){
            ans = ans * i / j;
        }
        return ans;
    }
public:
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        if (k > 26) return 0;
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for (char c: s) cnt[c - 'a']++;
        int idx[26];
        iota(idx, idx + 26, 0);
        sort(idx, idx + 26, [&](int a, int b) {return cnt[a] > cnt[b];});
        
        long long ans = 1;
        int std = cnt[idx[k - 1]], cur = 0;
        if (std == 0) return 0;
        int i = 0;
        for (; i < 26; i++) {
            if (cnt[idx[i]] > std) ans = (ans * cnt[idx[i]]) % mod;
            else if (cnt[idx[i]] == std) cur++;
            else break;
        }
        if (k < 26 && cnt[idx[k]] == std) {
            ans = (ans * C(cur, cur - i + k)) % mod;
            for (int j = 0; j < cur - i + k; j++) ans = (ans * std) % mod;
            cout << ans << endl;
        } else for (int i = 0; i < cur; i++) ans = (ans * std) % mod;
        return ans;
    }
};
