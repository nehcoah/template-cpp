class Solution {
public:
    int numberOfChild(int n, int k) {
        int i = 0;
        for (int d = 1, c = 0; c < k; c++, i += d) {
            if (i == 0) d = 1;
            if (i == n - 1) d = -1;
        }
        return i;
    }
};
