class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum = 0;
        for (char c : to_string(x)) {
            sum += c - '0';
        }
        return x % sum == 0 ? sum : -1;
    }
};
