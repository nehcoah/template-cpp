class Solution {
public:
    int countCompleteSubstrings(string s, int k) {
        int n = s.size(), pre = 0, res = 0;
        
        auto check = [&](int l, int r) {
            int ans = 0;
            for (int j = 1; j <= 26 && j * k <= r - l + 1; j++) {
                vector<int> cnt(26), num(r - l + 5);
                num[0] = 26;
                int len = j * k;
                for (int x = l; x <= r && x < l + len; x++) {
                    int c = s[x] - 'a';
                    num[cnt[c]]--; cnt[c]++; num[cnt[c]]++;
                }
                if (num[k] == j && num[k] + num[0] == 26) ans++;
                
                for (int x = l + len; x <= r; x++) {
                    char c = s[x] - 'a';
                    num[cnt[c]]--; cnt[c]++; num[cnt[c]]++;
                    c = s[x - len] - 'a';
                    num[cnt[c]]--; cnt[c]--; num[cnt[c]]++;
                    if (num[k] == j && num[k] + num[0] == 26) ans++;
                }
            }
            return ans;
        };
        
        for (int i = 0; i < n; i++) {
            if (i == n - 1 || abs(s[i + 1] - s[i]) > 2) {
                int l = pre, r = i;
                pre = i + 1;
                res += check(l, r);
            }
        }
        return res;
    }
};
