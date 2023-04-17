/*
 * @lc app=leetcode id=1189 lang=cpp
 *
 * [1189] Maximum Number of Balloons
 *
 * https://leetcode.com/problems/maximum-number-of-balloons/description/
 *
 * algorithms
 * Easy (61.20%)
 * Likes:    1408
 * Dislikes: 81
 * Total Accepted:    145.1K
 * Total Submissions: 238.1K
 * Testcase Example:  '"nlaebolko"'
 *
 * Given a string text, you want to use the characters of text to form as many
 * instances of the word "balloon" as possible.
 *
 * You can use each character in text at most once. Return the maximum number
 * of instances that can be formed.
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input: text = "nlaebolko"
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 *
 *
 * Input: text = "loonbalxballpoon"
 * Output: 2
 *
 *
 * Example 3:
 *
 *
 * Input: text = "leetcode"
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= text.length <= 10^4
 * text consists of lower case English letters only.
 *
 *
 */
#include <headers.h>
// @lc code=start
class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        int bCount = 0, aCount = 0, lCount = 0, oCount = 0, nCount = 0;

        // Count the frequencey of all the five characters
        for (int i = 0; i < text.length(); i++)
        {
            if (text[i] == 'b')
            {
                bCount++;
            }
            else if (text[i] == 'a')
            {
                aCount++;
            }
            else if (text[i] == 'l')
            {
                lCount++;
            }
            else if (text[i] == 'o')
            {
                oCount++;
            }
            else if (text[i] == 'n')
            {
                nCount++;
            }
        }

        // Find the potential of each character.
        // Except for 'l' and 'o' the potential is equal to the frequency.
        lCount = lCount / 2;
        oCount = oCount / 2;

        // Find the bottleneck.
        return min({bCount, aCount, lCount, oCount, nCount});
    }
};
// @lc code=end
