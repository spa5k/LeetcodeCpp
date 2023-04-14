/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 */
#include <headers.h>
int guess(int num);

// @lc code=start
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 */

class Solution
{
public:
    int guessNumber(int n)
    {
        int start = 1, end = n;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            int pos = guess(mid);
            if (pos == 0)
                return mid;
            if (pos == -1)
                end = mid - 1;
            else
                start = mid + 1;
        }

        return -1;
    }
};
// @lc code=end

int guess(int num)
{
    return 0;
}
