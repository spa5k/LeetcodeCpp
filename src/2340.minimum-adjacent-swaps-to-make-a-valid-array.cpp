/*
 * @lc app=leetcode id=2340 lang=cpp
 *
 * [2340] Minimum Adjacent Swaps to Make a Valid Array
 */
#include <headers.h>

// @lc code=start
class Solution
{
public:
    int minimumSwaps(vector<int> &nums)
    {
        // find index of both the leftmost minimum and the rightmost maximum
        int n = nums.size();
        int min = INT_MAX;
        int argmin = 0;
        int max = -INT_MAX;
        int argmax = n - 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (min > nums[i])
            {
                min = nums[i];
                argmin = i;
            }
            if (max < nums[n - i - 1])
            {
                max = nums[n - i - 1];
                argmax = n - i - 1;
            }
        }
        int ans = (n - 1) - argmax + argmin;
        return argmin > argmax ? ans - 1 : ans;
    }
};
// @lc code=end
