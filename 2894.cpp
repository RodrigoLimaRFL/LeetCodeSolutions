#include <iostream>

using namespace std;

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sumAllNumbers = n * (n + 1) / 2;
        
        if(m > n)
        {
            return sumAllNumbers;
        }

        int numberDivisors = n / m;
        int biggestDivisor = numberDivisors * m;

        int sumDivisor = numberDivisors * (biggestDivisor + m) / 2;

        return sumAllNumbers - (sumDivisor * 2);
    }
};

int main() {
    Solution solution;

    int n = 5, m = 1;

    int answer = solution.differenceOfSums(n, m);

    cout << answer << endl;
}