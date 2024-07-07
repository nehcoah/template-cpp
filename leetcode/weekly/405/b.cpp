class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        string cur;
        auto dfs = [&](auto self, int i) {
            if (i == n) {
                ans.push_back(cur);
                return;
            }
            if (cur.empty() || cur.back() == '1') {
                cur += "0";
                self(self, i + 1);
                cur.back() = '1';
                self(self, i + 1);
                cur.pop_back();
            }
            if (!cur.empty() && cur.back() == '0') {
                cur += "1";
                self(self, i + 1);
                cur.pop_back();
            }
        };
        dfs(dfs, 0);
        return ans;
    }
};
