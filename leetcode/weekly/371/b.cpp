class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<int>> mp;
        for (auto &a : access_times) {
            int t = stoi(a[1].substr(0, 2)) * 60 + stoi(a[1].substr(2));
            mp[a[0]].push_back(t);
        }
        vector<string> ans;
        for (auto [s, t] : mp) {
            ranges::sort(t);
            if (t.size() < 3) continue;
            for (int i = 0; i < t.size() - 2; i++) {
                if (t[i + 2] - t[i] < 60) {
                    ans.push_back(s);
                    break;
                }
            }
        }
        return ans;
    }
};
