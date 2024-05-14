class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<int> pos(26, -1);
        for (int i = 0; i < s.size(); i++) {
            pos[s[i] - 'a'] = i;
        }
        int ans = 0;
        for (int i = 0; i < t.size(); i++) {
            ans += abs(i - pos[t[i] - 'a']);
        }
        return ans;
    }
};
