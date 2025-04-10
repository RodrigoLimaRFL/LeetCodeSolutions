#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            vector<bool> hasAppeared(101, false);
            int n = nums.size();
            int i = n - 1;
            bool appeared = false;

            while(i >= 0)
            {
                if(hasAppeared[nums[i]])
                {
                    appeared = true;
                    break;
                }
                
                hasAppeared[nums[i]] = true;

                i--;
            }

            if(!appeared)
            {
                return 0;
            }

            int ammountToCut = i + 1;
            
            if(ammountToCut % 3 == 0)
            {
                return ammountToCut/3;
            }
            else
            {
                return (ammountToCut/3) + 1;
            }
        }
};


int main() {
    Solution solution;
    vector<int> nums = {5, 5};
    int result = solution.minimumOperations(nums);
    cout << "Minimum operations: " << result << endl;

    return 0;
}