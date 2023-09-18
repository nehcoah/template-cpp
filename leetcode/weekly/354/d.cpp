// https://leetcode.cn/problems/length-of-the-longest-valid-substring/

class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        int n = word.size();
        unordered_set<string> st;
        for (auto& s : forbidden) st.insert(s);
        int ans = 0, l = 0, r = 0;
        while (r < n) {
            bool flag = false;
            int cur = l;
            for (int i = 0; i < min(11, r - l + 1); i++) {
                if (st.count(word.substr(r - i, i + 1))) {
                    cur = r - i;
                    flag = true;
                    break;
                }
            }
            if (flag) {
                ans = max(ans, r - l);
                l = cur + 1;
                r = l;
            } else {
                r++;
                if (r == n) ans = max(ans, r - l);
            }
        }
        return ans;
    }
};
