/*
 * @lc app=leetcode id=1863 lang=cpp
 *
 * [1863] Sum of All Subset XOR Totals
 */
#include <headers.h>
class Solutions
{
public:
    int subsetXORSum(vector<int> &nums)
    {
        return dfs(nums, 0, 0);
    }

    int dfs(vector<int> &nums, int index, int currentXor)
    {
        if (index == nums.size())
        {
            return currentXor;
        }
        int withElement = dfs(nums, index + 1, currentXor ^ nums[index]);

        int withoutElement = dfs(nums, index + 1, currentXor);
        return withElement + withoutElement;
    }
};

// @lc code=start

class Solution
{
    void dfs(int start_index, vector<int> &nums, int currentXor, vector<int> &path, int &result)
    {
        if (start_index == nums.size())
        {
            result += currentXor;
            return;
        }
        // include current element in the subset
        path.push_back(nums[start_index]);
        dfs(start_index + 1, nums, currentXor ^ nums[start_index], path, result);
        path.pop_back();
        // exclude current element from the subset
        dfs(start_index + 1, nums, currentXor, path, result);
    }

public:
    int subsetXORSum(vector<int> &nums)
    {
        vector<int> path;
        int result = 0;
        dfs(0, nums, 0, path, result);
        return result;
    }
};

// @lc code=end
