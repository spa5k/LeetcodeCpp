/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (43.75%)
 * Likes:    17835
 * Dislikes: 519
 * Total Accepted:    957.4K
 * Total Submissions: 2.2M
 * Testcase Example:  '[1,1,1]\n2'
 *
 * Given an array of integers nums and an integer k, return the total number of
 * subarrays whose sum equals to k.
 *
 * A subarray is a contiguous non-empty sequence of elements within an
 * array.
 *
 *
 * Example 1:
 * Input: nums = [1,1,1], k = 2
 * Output: 2
 * Example 2:
 * Input: nums = [1,2,3], k = 3
 * Output: 2
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 2 * 10^4
 * -1000 <= nums[i] <= 1000
 * -10^7 <= k <= 10^7
 *
 *
 */
#include <headers.h>
// @lc code=start
class Solution
{
public:
    int subarraySum(vector<int> &arr, int k)
    {
        int n = arr.size(); // take the size of the array

        int prefix[n]; // make a prefix array to store prefix sum

        prefix[0] = arr[0]; // for element at index at zero, it is same

        // making our prefix array
        for (int i = 1; i < n; i++)
        {
            prefix[i] = arr[i] + prefix[i - 1];
        }

        unordered_map<int, int> mp; // declare an unordered map

        int ans = 0; // to store the number of our subarrays having sum as 'k'

        for (int i = 0; i < n; i++) // traverse from the prefix array
        {
            if (prefix[i] == k) // if it already becomes equal to k, then increment ans
                ans++;

            // now, as we discussed find whether (prefix[i] - k) present in map or not
            if (mp.find(prefix[i] - k) != mp.end())
            {
                ans += mp[prefix[i] - k]; // if yes, then add it our answer
            }

            mp[prefix[i]]++; // put prefix sum into our map
        }

        return ans; // and at last, return our answer
    }
};
// @lc code=end
