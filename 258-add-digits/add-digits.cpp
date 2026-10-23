
class Solution {
public:
    int addDigits(int num) {
        if (num < 10)
            return num;

        return addDigits(sum(num));
    }

    int sum(int num) {
        if (num == 0)
            return 0;

        return num % 10 + sum(num / 10);
    }
};
