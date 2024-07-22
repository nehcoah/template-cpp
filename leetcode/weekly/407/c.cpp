class Solution {
public:
    int maxOperations(string s) {
        int ans = 0, n = s.size(), cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                int j = i;
                while (j < n && s[j] == '1') j += 1;
                if (j < n) {
                    cnt += j - i;
                    ans += cnt;
                }
                i = j;
            }
        }
        return ans;
    }
};
