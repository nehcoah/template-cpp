class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        int cnt = 0;
        set<string> st{bannedWords.begin(), bannedWords.end()};
        for (auto &s : message) {
            if (st.count(s)) cnt += 1;
        }
        return cnt >= 2;
    }
};
