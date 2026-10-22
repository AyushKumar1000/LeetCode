
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        unsigned int div = 1;

        for (int i = 0; i < 32; i++) {
            int res = n & div;

            if (res != 0)
                count++;

            div = 2 * div;
        }

        return count;
    }
};
