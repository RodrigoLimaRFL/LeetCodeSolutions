#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int end = 0;

        int n = nums.size();
        int i = 0;

        while (i < n)
        {
            if (nums[i] != val)
            {
                nums[end] = nums[i];
                end++;
            }
            i++;
        }

        return end;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    int result = solution.removeElement(nums, val);
    cout << result << endl;
    for (int i = 0; i < result; i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}