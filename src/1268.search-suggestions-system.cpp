/*
 * @lc app=leetcode id=1268 lang=cpp
 *
 * [1268] Search Suggestions System
 */
#include <headers.h>
// @lc code=start
class Solution
{
public:
    vector<vector<string>> suggestedProducts(vector<string> &A, string searchWord)
    {
        auto it = A.begin();
        sort(it, A.end());

        vector<vector<string>> res;
        string curr = "";
        for (auto &&c : searchWord)
        {
            curr += c;
            vector<string> suggested;
            it = lower_bound(it, A.end(), curr);
            for (int i = 0; i < 3 && it + i != A.end(); i++)
            {
                string &s = *(it + i);
                if (s.find(curr))
                    break;
                suggested.push_back(s);
            }
            res.push_back(suggested);
        }
        return res;
    }
};

// @lc code=end
