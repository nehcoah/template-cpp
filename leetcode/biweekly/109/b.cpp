// 2785
// https://leetcode.cn/problems/sort-vowels-in-a-string/
// sorting

class Solution {
public:
    string sortVowels(string s) {
        auto check = [](char c) {return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';};
        string ss;
        vector<int> idx;
        for (int i = 0; i < s.size(); i++) {
            if (check(s[i])) ss.push_back(s[i]), idx.push_back(i);
        }
        sort(ss.begin(), ss.end());
        for (int i = 0; i < idx.size(); i++) s[idx[i]] = ss[i];
        return s;
    }
};
