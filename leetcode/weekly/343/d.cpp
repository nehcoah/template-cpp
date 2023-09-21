// https://leetcode.cn/problems/lexicographically-smallest-beautiful-string/

class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        k += 'a';
        int n = s.size(), i = n - 1;
        s[i]++;
        while (i < n){
            if (s[i] == k){
                if (i == 0) return "";
                s[i] = 'a';
                s[--i]++;
            } else if (i > 0 && s[i] == s[i - 1] || i > 1 && s[i] == s[i - 2]){
                s[i]++;
            } else i++;
        }
        return s;
    }
};
