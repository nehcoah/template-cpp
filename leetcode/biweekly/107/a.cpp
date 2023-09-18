// https://leetcode.cn/problems/find-maximum-number-of-string-pairs/

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int ans = 0, n = words.size();
        for (int i = 0; i < n; i++){
            string s = words[i];
            reverse(s.begin(), s.end());
            for (int j = i + 1; j < n; j++) if (s == words[j]) ans++;
        }
        return ans;
    }
};
