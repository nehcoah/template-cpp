class Solution {
public:
    long long flowerGame(int n, int m) {
        int a = n / 2 + n % 2, b = n / 2;
        int c = m / 2 + m % 2, d = m / 2;
        return 1ll * a * d + 1ll * b * c;
    }
};
