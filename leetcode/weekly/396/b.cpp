class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string, int> mp;
        int n = word.size();
        for (int i = 0; i < n; i += k) {
            mp[word.substr(i, k)] += 1;
        }
        int tot = 0, mx = 0;
        for (auto &[k, v] : mp) {
            tot += v;
            mx = max(mx, v);
        }
        return tot - mx;
    }
};
