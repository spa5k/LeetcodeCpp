/*
 * @lc app=leetcode id=2405 lang=cpp
 *
 * [2405] Optimal Partition of String
 */
#include <headers.h>

// @lc code=start
class Solution
{
public:
    int partitionString(string s)
    {
        unordered_set<char> st;
        int count = 1;
        for (int i = 0; i < s.size(); i++)
        {
            if (st.find(s[i]) != st.end())
            {
                count++;
                st.clear();
            }
            st.insert(s[i]);
        }
        return count;
    }
};
// @lc code=end
