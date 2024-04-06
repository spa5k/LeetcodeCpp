/*
 * @lc app=leetcode id=1151 lang=cpp
 *
 * [1151] Minimum swaps to group all 1s together
 */
#include <headers.h>

// @lc code=start
class Solution
{
public:
    int minSwaps(vector<int> &data)
    {
        // Make a full pass to count the number of ones.
        int countOfOnes = 0;
        for (int val : data)
            if (val == 1)
                countOfOnes++;

        // Make a second pass with a sliding window to find the window with the largest number of ones.
        const int slidingWidth = countOfOnes;
        int numOnes = 0;
        int maxOnes = 0;
        for (int slidingEnd = 0; slidingEnd < data.size(); slidingEnd++)
        {
            if (data[slidingEnd] == 1)
                numOnes++;
            if (slidingEnd >= slidingWidth - 1)
            {
                int slidingStart = slidingEnd + 1 - slidingWidth;
                if (slidingStart >= 1 && data[slidingStart - 1] == 1)
                    --numOnes;
            }
            maxOnes = max(maxOnes, numOnes);
        }

        // The result is the fewest number of zeros in a sliding window.
        return countOfOnes - maxOnes;
    }
};
// @lc code=end
