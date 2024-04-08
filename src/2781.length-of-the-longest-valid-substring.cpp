/*
 * @lc app=leetcode id=2781 lang=cpp
 *
 * [2781] Length of the Longest Valid Substring
 */
#include <headers.h>

// @lc code=start
class Solution
{
public:
    int longestValidSubstring(string word, vector<string> &forbidden)
    {
        unordered_map<string, int> map;
        for (auto &&w : word)
        {
            map.emplace(w);
        }
    }
};
// @lc code=end
