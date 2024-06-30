class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        auto check = [&](int r, int b) {
            for (int i = 1; ; i++) {
                if (i % 2 == 1) {
                    if (r >= i) r -= i;
                    else return i - 1;
                } else {
                    if (b >= i) b -= i;
                    else return i - 1;
                }
            }
            return 0;
        };
        return max(check(red, blue), check(blue, red));
    }
};
