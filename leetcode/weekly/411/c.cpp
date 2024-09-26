class Solution {
public:
    string largestPalindrome(int n, int k) {
        if (k == 1 || k == 3 || k == 9) return string(n, '9');
        if (k == 2) {
            if (n == 1) return "8";
            return "8" + string(n - 2, '9') + "8";
        }
        if (k == 4) {
            if (n <= 3) return string(n, '8');
            return "88" + string(n - 4, '9') + "88";
        }
        if (k == 5) {
            if (n == 1) return "5";
            return "5" + string(n - 2, '9') + "5";
        }
        if (k == 6) {
            if (n <= 2) return string(n, '6');
            if (n == 3) return "888";
            if (n % 2 == 1) return "8" + string((n - 3) / 2, '9') + "8" + string((n - 3) / 2, '9') + "8";
            else return "8" + string((n - 4) / 2, '9') + "77" + string((n - 4) / 2, '9') + "8";
        }
        if (k == 7) {
            if (n % 6 == 0) return string(n, '9');
            if (n % 12 == 1) return string(n / 2, '9') + "7" + string(n / 2, '9');
            if (n % 12 == 2) return string(n / 2 - 1, '9') + "77" + string(n / 2 - 1, '9');
            if (n % 12 == 3) return string(n / 2 - 1, '9') + "959" + string(n / 2 - 1, '9');
            if (n % 12 == 4) return string(n / 2 - 2, '9') + "9779" + string(n / 2 - 2, '9');
            if (n % 12 == 5) return string(n / 2 - 2, '9') + "99799" + string(n / 2 - 2, '9');
            if (n % 12 == 7) return string(n / 2 - 3, '9') + "9994999" + string(n / 2 - 3, '9');
            if (n % 12 == 8) return string(n / 2 - 4, '9') + "99944999" + string(n / 2 - 4, '9');
            if (n % 12 == 9) return string(n / 2 - 4, '9') + "999969999" + string(n / 2 - 4, '9');
            if (n % 12 == 10) return string(n / 2 - 5, '9') + "9999449999" + string(n / 2 - 5, '9');
            if (n % 12 == 11) return string(n / 2 - 5, '9') + "99999499999" + string(n / 2 - 5, '9');
        }
        if (k == 8) {
            if (n <= 6) return string(n, '8');
            return "888" + string(n - 6, '9') + "888";
        }
        return "";
    }
};
