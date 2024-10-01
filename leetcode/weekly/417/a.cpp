class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while (s.size() < k) {
            for (int i = 0, j = s.size(); j > 0; i++, j--) {
                char nxt = s[i] == 'z' ? 'a' : s[i] + 1;
                s += nxt;
            }
        }
        return s[k - 1];
    }
};
