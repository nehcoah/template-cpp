class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> cnt(26);
        for (char c : word) {
            if (islower(c)) {
                cnt[c - 'a'] |= 1;
                if (cnt[c - 'a'] >> 1 & 1) cnt[c - 'a'] = -1;
            }
            if (isupper(c)) cnt[c - 'A'] |= 2;
        }
        return count(cnt.begin(), cnt.end(), 3);
    }
};
