// 2840
// https://leetcode.cn/problems/check-if-strings-can-be-made-equal-with-operations-ii/description/
// brute force

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < s1.size(); i += 2) {
            cnt[s1[i] - 'a']++;
            cnt[s2[i] - 'a']--;
        }
        for (int x : cnt) if (x != 0) return false;
        for (int i = 1; i < s1.size(); i += 2) {
            cnt[s1[i] - 'a']++;
            cnt[s2[i] - 'a']--;
        }
        for (int x : cnt) if (x != 0) return false;
        return true;
    }
};
