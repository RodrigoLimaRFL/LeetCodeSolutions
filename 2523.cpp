#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i <= right; i++) {
            if (isPrime[i] && (long long)i * i <= right) {
                for (int j = i * i; j <= right; j += i)
                    isPrime[j] = false;
            }
        }

        vector<int> primes;

        for (int i = left; i <= right; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }

        int minDiff = INT_MAX;
        vector<int> result(2);

        for (long long unsigned int i = 1; i < primes.size(); i++) {
            if (primes[i] - primes[i - 1] < minDiff) {
                minDiff = primes[i] - primes[i - 1];
                result[0] = primes[i - 1];
                result[1] = primes[i];
            }
        }

        if(minDiff == INT_MAX)
        {
            return {-1, -1};
        }

        return result;
    }
};

int main()
{
    Solution solution;
    int left = 50;
    int right = 80;
    vector<int> result = solution.closestPrimes(left, right);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}