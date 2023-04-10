/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */
#include <headers.h>
// @lc code=start
class Solution
{
public:
    int myAtoi(string s)
    {
        int sign = 1;
        int res = 0;
        int index = 0;
        int n = s.size();

        while (index < n && s[index] == ' ')
        {
            index++;
        }

        if (index < n && s[index] == '-')
        {
            sign = -1;
            index++;
        }
        else if (index < n && s[index] == '+')
        {
            index++;
        }

        while (index < n && isdigit(s[index]))
        {
            int digit = s[index] - '0';
            if ((res > INT_MAX / 10) || (res == INT_MAX / 10 && digit > INT_MAX % 10))
            {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            res = res * 10 + digit;
            index++;
        }
        return sign * res;
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

    int ans = solution.myAtoi("+1");
    cout << "The answer is: [" << ans << "]." << endl;

    return 0;
}