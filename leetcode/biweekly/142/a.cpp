class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        int ans = 1;
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && word[i] == word[j]) j += 1;
            ans += j - i - 1;
            i = j;
        }
        return ans;
    }
};
