/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */
#include "headers.h"

// @lc code=start
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> mapS;
        unordered_map<char, char> mapT;

        if (s.size() != t.size())
        {
            return false;
        }

        for (int i = 0; i < s.size(); i++)
        {
            char charS = s[i];
            char charT = t[i];

            if (mapS.find(charS) != mapS.end())
            {
                if (mapS[charS] != charT)
                {
                    return false;
                }
            }
            else
            {
                if (mapT.find(charT) != mapS.end())
                {
                    return false;
                }

                mapS[charS] = charT;
                mapT[charT] = charS;
            }
        }
        return true;
    }
};
// @lc code=end
