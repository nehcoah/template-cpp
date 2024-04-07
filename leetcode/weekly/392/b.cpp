class Solution {
public:
    string getSmallestString(string s, int k) {
        for (char &c : s) {
            int x1 = 'z' - c + 1;
            int x2 = c - 'a';
            if (x1 <= x2) {
                if (x1 <= k) c = 'a', k -= x1;
                else c = c - min(x2, k), k = k - min(x2, k);
            } else {
                if (x2 < k) c = 'a', k -= x2;
                else c = c - k, k = 0;
            }
            if (k == 0) return s;
        }
        return s;
    }
};
