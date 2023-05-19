/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */
#include <headers.h>
// @lc code=start
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<char> path;
        vector<string> res;
        dfs(0, path, 0, 0, res, n);
        return res;
    }

    void dfs(int startIndex, vector<char> &path, int openCount, int closeCount, vector<string> &res, int n)
    {
        // it means that there are equal number of closing and opening brackets and they both are equal to n;
        if (path.size() == 2 * n)
        {
            res.emplace_back(path.begin(), path.end());
            return;
        }
        if (openCount < n)
        {
            path.emplace_back('(');
            dfs(startIndex + 1, path, openCount + 1, closeCount, res, n);
            path.pop_back();
        }
        if (closeCount < openCount)
        {
            path.emplace_back(')');
            dfs(startIndex + 1, path, openCount, closeCount + 1, res, n);
            path.pop_back();
        }
    }
};
// @lc code=end
