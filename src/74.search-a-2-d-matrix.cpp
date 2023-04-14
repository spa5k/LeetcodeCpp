/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 *
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (47.52%)
 * Likes:    11909
 * Dislikes: 344
 * Total Accepted:    1.2M
 * Total Submissions: 2.5M
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n3'
 *
 * You are given an m x n integer matrix matrix with the following two
 * properties:
 *
 *
 * Each row is sorted in non-decreasing order.
 * The first integer of each row is greater than the last integer of the
 * previous row.
 *
 *
 * Given an integer target, return true if target is in matrix or false
 * otherwise.
 *
 * You must write a solution in O(log(m * n)) time complexity.
 *
 *
 * Example 1:
 *
 *
 * Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 100
 * -10^4 <= matrix[i][j], target <= 10^4
 *
 *
 */
#include <headers.h>
// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        for (auto &&mat : matrix)
        {
            bool res = binarySearch(mat, target);
            if (res)
            {
                return true;
            }
        }
        return false;
    }

    bool binarySearch(vector<int> &matrix, int target)
    {
        int left = 0;
        int right = matrix.size() - 1;
        if (target < matrix[left] || target > matrix[right])
        {
            return false;
        }

        while (left <= right)
        {
            int mid = (left + right) / 2;
            int midn = matrix[mid];
            if (target == midn)
            {
                return true;
            }
            else if (target < midn)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return false;
    }
};
// @lc code=end
