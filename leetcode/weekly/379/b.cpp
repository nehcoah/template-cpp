class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        int ans = 5;
        if ((c + d) % 2 == (e + f) % 2) {
            if (c + d == e + f) {
                if (c + d == a + b && (c >= a && a >= e || c <= a && a <= e)) {
                    ans = min(ans, 2);
                } else {
                    ans = min(ans, 1);
                }
            } else if (c - d == e - f) {
                if (c - d == a - b && (c >= a && a >= e || c <= a && a <= e)) {
                    ans = min(ans, 2);
                } else {
                    ans = min(ans, 1);
                }
            } else ans = min(ans, 2);
        }
        if (a == e) {
            if (c == e && (b <= d && d <= f || f <= d && d <= b)) {
                ans = min(ans, 2);
            } else {
                ans = min(ans, 1);
            }
        } else if (b == f) {
            if (d == f && (a <= c && c <= e || e <= c && c <= a)) {
                ans = min(ans, 2);
            } else {
                ans = min(ans, 1);
            }
        } else {
            ans = min(ans, 2);
        }
        return ans;
    }
};
