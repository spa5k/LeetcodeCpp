/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */
#include <headers.h>
// @lc code=start
class Solution
{
public:
    bool isValid(string string)
    {
        stack<char> stack;

        if (string.size() == 0)
        {
            return true;
        }

        for (auto &&i : string)
        {
            if (i == '(' || i == '[' || i == '{')
            {
                stack.push(i);
            }
            else if ((i == ')' && !stack.empty() && stack.top() == '(') ||
                     (i == '}' && !stack.empty() && stack.top() == '{') ||
                     (i == ']' && !stack.empty() && stack.top() == '['))
            {
                stack.pop();
            }
            else
            {
                return false;
            }
        }
        if (stack.empty())
        {
            return true;
        }
        return false;
    }
};

int main(int argc, char **argv)
{
    Solution solution;
    // vector<int> nums = {2, 7, 11, 15};
    // int target = 9;
    vector<int> nums = {3, 2, 3};
    int target = 6;

    bool ans = solution.isValid("(])");
    cout << "The answer is: [" << ans << "]." << endl;

    return 0;
}

// @lc code=end
