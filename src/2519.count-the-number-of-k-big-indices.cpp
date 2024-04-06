/*
 * @lc app=leetcode id=2519 lang=cpp
 *
 * [2519] Count the Number of K-Big Indices
 */
#include <headers.h>

// @lc code=start
class Solution
{
public:
    int kBigIndices(vector<int> &nums, int k)
    {
        int count = 0;
        int n = nums.size();

        vector<bool> prefix(n);
        priority_queue<int> pq;
        for (int i = 0; i < n; i++)
        {
            if (pq.size() == k && pq.top() < nums[i])
            {
                prefix[i] = true;
            }
            pq.push(nums[i]);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        int ans = 0;

        pq = priority_queue<int>();

        for (int i = n - 1; i >= 0; --i)
        {
            if (pq.size() == k && pq.top() < nums[i] && prefix[i])
            {
                ans++;
            }
            pq.push(nums[i]);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        return ans;
    }
};
// @lc code=end
