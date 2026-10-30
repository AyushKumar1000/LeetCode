class Solution {
public:

    bool isPrime(int n) {
        if (n < 2)
            return false;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }

        return true;
    }

    vector<int> closestPrimes(int left, int right) {

        vector<int> ans = {-1, -1};

        int prev = -1;
        int minDiff = INT_MAX;

        for (int i = left; i <= right; i++) {

            if (isPrime(i)) {

                if (prev != -1) {

                    int diff = i - prev;

                    if (diff < minDiff) {
                        minDiff = diff;

                        ans[0] = prev;
                        ans[1] = i;
                    }

                    if (minDiff == 2)
                        return ans;
                }

                prev = i;
            }
        }

        return ans;
    }
};