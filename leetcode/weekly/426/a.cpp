class Solution {
public:
    int smallestNumber(int n) {
        for (int i = 0; i < 12; i++) {
            if (int(pow(2, i)) - 1 >= n) {
                return int(pow(2, i)) - 1;
            }
        }
        return -1;
    }
};
