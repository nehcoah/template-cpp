// https://leetcode.cn/problems/lexicographically-smallest-string-after-substring-operation/description/

class Solution {
public:
    string smallestString(string s) {
        int i = 0;
        while (i < s.size() && s[i] == 'a') i++;
        if (i == s.size()) {
            s[s.size() - 1] = 'z';
            return s;
        }
        int j = i;
        while (j < s.size() && s[j + 1] != 'a') j++;
        for (int k = i; k <= j; k++) s[k]--;
        return s;
    }
};
