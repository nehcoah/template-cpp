// 2800
// https://leetcode.cn/problems/shortest-string-that-contains-three-strings/description/
// brute force

class Solution {
public:
    string minimumString(string a, string b, string c) {
        auto merge = [](string x, string y, string z) {
            auto concat = [](string a, string b) {
                if (a.find(b) != a.npos) return a;
                for (int i = min(a.size(), b.size()); i > 0; i--) {
                    if (a.substr(a.size() - i) == b.substr(0, i)) return a + b.substr(i);
                }
                return a + b;
            };
            return concat(concat(x, y), z);
        };
        string ans[6] = {merge(a, b, c), merge(a, c, b), merge(b, a, c), merge(b, c, a), merge(c, a, b), merge(c, b, a)};
        sort(ans, ans + 6, [](auto x, auto y) {
            int m = x.size(), n = y.size();
            return m == n ? x < y : m < n;
        });
        return ans[0];
    }
};
