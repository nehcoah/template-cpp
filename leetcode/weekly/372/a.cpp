class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        int ans = 0;
        bool ok = false;
        for (int i = 0; i < min({n1, n2, n3}); i++) {
            if (!(s1[i] == s2[i] && s2[i] == s3[i])) {
                ans = i * 3;
                ok = true;
                break;
            }
        }
        if (!ok) ans = min({n1, n2, n3}) * 3;
        return ans == 0 ? -1 : n1 + n2 + n3 - ans;
    }
};
