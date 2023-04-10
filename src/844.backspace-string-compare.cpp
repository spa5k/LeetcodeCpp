/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */
#include <headers.h>
// @lc code=start
class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> s1;
        stack<char> s2;

        for (auto &&i : s)
        {
            if (i == '#')
            {
                if (s1.size() > 0)
                {
                    s1.pop();
                }
            }
            else
            {
                s1.push(i);
            }
        }

        for (auto &&i : t)
        {
            if (i == '#')
            {
                if (s2.size() > 0)
                {
                    s2.pop();
                }
            }
            else
            {
                s2.push(i);
            }
        }

        if (s1.size() != s2.size())
        {
            return false;
        }
        while (!s1.empty())
        {
            char t1 = s1.top();
            s1.pop();
            char t2 = s2.top();
            s2.pop();
            if (t1 != t2)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

int main(int argc, char **argv)
{
    Solution solution;
    // vector<int> nums = {2, 7, 11, 15};
    // int target = 9;
    vector<int> nums = {3, 2, 3};
    int target = 6;

    bool ans = solution.backspaceCompare("abcd", "bbcd");
    cout << "The answer is: [" << ans << "]." << endl;

    return 0;
}
