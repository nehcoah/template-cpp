class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt = count_if(s.begin(), s.end(), [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        });
        return cnt != 0;
    }
};
