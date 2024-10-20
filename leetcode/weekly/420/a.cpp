class Solution {
public:
    vector<string> stringSequence(string target) {
        string s;
        vector<string> ans;
        for (int i = 0; i < target.size(); i++) {
            s += 'a';
            ans.push_back(s);
            while (s.back() != target[i]) {
                s.back() += 1;
                ans.push_back(s);
            }
        }
        return ans;
    }
};
