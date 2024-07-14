class Solution {
public:
    string getSmallestString(string s) {
        string ans = s;
        for (int i = 0; i < s.size() - 1; i++) {
            if ((s[i] - '0') % 2 == (s[i + 1] - '0') % 2) {
                auto t = s;
                swap(t[i], t[i + 1]);
                ans = min(ans, t);
            }
        }
        return ans;
    }
};
