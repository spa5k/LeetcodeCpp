/*
 * @lc app=leetcode id=2422 lang=cpp
 *
 * [2422] Merge Operations to Turn Array Into a Palindrome
 */
#include <headers.h>

// @lc code=start
class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        vector<long long> copy_nums(nums.begin(), nums.end());

        int count = 0;
        int left = 0;
        int right = nums.size() - 1;

        while (left < right)
        {
            if (copy_nums[left] == copy_nums[right])
            {
                left++;
                right--;
            }
            else if (copy_nums[left] > copy_nums[right])
            {
                copy_nums[right - 1] += copy_nums[right];
                right--;
                count++;
            }
            else
            {
                copy_nums[left + 1] += copy_nums[left];
                left++;
                count++;
            }
        }
        return count;
    }
};
// @lc code=end
