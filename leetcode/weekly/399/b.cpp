class Solution {
public:
    string compressedString(string word) {
        string ans;
        int n = word.size(), pre = 0;
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && word[j] == word[i] && j - i + 1 < 10) j += 1;
            ans += to_string(j - i) + string(1, word[i]);
            i = j;
        }
        return ans;
    }
};
