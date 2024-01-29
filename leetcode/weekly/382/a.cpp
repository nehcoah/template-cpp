class Solution {
public:
    int countKeyChanges(string s) {
        int ans = 0;
        char t = tolower(s[0]);
        for (char c : s) {
            if (tolower(c) != t) {
                ans++;
                t = tolower(c);
            }
        }
        return ans;
    }
};
