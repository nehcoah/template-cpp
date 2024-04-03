class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long ans = 0, sum = 0;
        for (char ch : s) {
            if (ch == c) {
                sum += 1;
                ans += sum;
            }
        }
        return ans;
    }
};
