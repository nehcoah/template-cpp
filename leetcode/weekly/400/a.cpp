class Solution {
public:
    int minimumChairs(string s) {
        int mx = 0, cur = 0;
        for (char c : s) {
            if (c == 'E') {
                cur += 1, mx = max(mx, cur);
            } else {
                cur -= 1;
            }
        }
        return mx;
    }
};
