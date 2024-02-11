class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        array<int, 26> cnt{};
        for (auto &s : words) {
            for (char c : s) {
                cnt[c - 'a']++;
            }
        }
        int ans = words.size(), c = 0;
        vector<int> t;
        for (auto &s : words) t.push_back(s.size());
        for (int x : cnt) c += x % 2;
        sort(t.begin(), t.end());
        for (int i = 0; i < t.size(); i++) {
            if (t[i] % 2) t[i] -= 1, c -= 1;
        }
        for (int i = t.size() - 1; i >= 0 && c > 0; i--) {
            c -= t[i];
            ans--;
        }
        return ans;
    }
};
