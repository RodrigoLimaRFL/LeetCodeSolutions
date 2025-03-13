#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {


    }
};

/*class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int zeroAmount = 0;

        int numQueries = queries.size();

        vector<bool> isZero = vector<bool>(n, false);

        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 0)
            {
                isZero[i] = true;
                zeroAmount++;
            }
        }

        if(zeroAmount == n)
        {
            return 0;
        }

        for(int i = 0; i < numQueries; i++)
        {
            int left = queries[i][0];
            int right = queries[i][1];
            int maxAmount = queries[i][2];

            for(int j = left; j <= right; j++)
            {
                int number = nums[j];

                if(isZero[j] == true)
                {
                    continue;
                }

                if(nums[j] > maxAmount)
                {
                    nums[j] -= maxAmount;
                }
                else
                {
                    nums[j] = 0;
                    isZero[j] = true;
                    zeroAmount++;
                }
            }

            if(zeroAmount == n)
            {
                return i+1;
            }
        }

        return -1;
    }
};*/

int main() {
    Solution solution;
    vector<int> nums = {2, 0, 2};
    vector<vector<int>> queries = {{0, 2, 1}, {0, 2, 1}, {1, 1, 3}};
    cout << solution.minZeroArray(nums, queries) << endl;
    return 0;
}