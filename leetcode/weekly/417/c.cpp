class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        auto check = [&](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        int n = word.size();
        long long cnt = 0, ans = 0;
        vector<int> pos{-1};
        unordered_map<char, int> mp;
        for (int r = 0, l = 0; r < n; r++) {
            if (check(word[r])) mp[word[r]] += 1;
            else cnt += 1, pos.push_back(r);
            while (l <= r) {
                if (mp.size() < 5 || cnt < k) break;
                if (check(word[l])) {
                    if (mp[word[l]] == 1) break;
                    mp[word[l]] -= 1;
                } else {
                    if (cnt == k) break;
                    cnt -= 1;
                }
                l += 1;
            }
            if (cnt == k && mp.size() == 5) {
                ans += l - pos[pos.size() - k - 1];
            }
        }
        return ans;
    }
};
