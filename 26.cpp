#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<bool> appeared(201, false); // -100 <= nums[i] <= 100

        int n = nums.size();
        int end = 0;

        for(int i = 0; i < n; i++) {
            if(!appeared[nums[i] + 100]) {
                appeared[nums[i] + 100] = true;
                nums[end] = nums[i];
                end++;
            }
        }

        return end;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 1, 2, 3, 3, 4};
    cout << s.removeDuplicates(nums) << endl;
    cout << "nums: ";
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    return 0;
}