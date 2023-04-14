/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */
#include <headers.h>
// @lc code=start
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high)
        {

            switch (nums[mid])
            {
            case 0:
                swap(nums[low++], nums[mid++]);
                break;

            case 1:
                mid++;
                break;

            case 2:
                swap(nums[mid], nums[high--]);
                break;
            }
        }
    }
};
// @lc code=end

int main(int argc, char **argv)
{
    Solution solution;
    // vector<int> nums = {2, 7, 11, 15};
    // int target = 9;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    int target = 6;

    solution.sortColors(nums);
    // cout << "The answer is: [" << ans << "]." << endl;

    return 0;
}
