class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n = word.size(), ans = 1;
        for (int i = k; i < n; i += k) {
            if (word.substr(i) == word.substr(0, n - i)) return ans;
            ans++;
        }
        return ans;
    }
};
