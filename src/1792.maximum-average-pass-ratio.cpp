/*
 * @lc app=leetcode id=1792 lang=cpp
 *
 * [1792] Maximum Average Pass Ratio
 */
#include <headers.h>
// @lc code=start
struct cmp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        double ad = (a.first + 1) / (double)(a.second + 1) - (a.first) / (double)a.second;
        double bd = (b.first + 1) / (double)(b.second + 1) - (b.first) / (double)b.second;
        return ad < bd;
    }
};

class Solution
{
public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        double acc = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq{};
        for (auto &&i : classes)
        {
            pq.push({i[0], i[1]});
        }
        while (extraStudents--)
        {
            pair<int, int> cur = pq.top();
            pq.pop();
            cur.first++;
            cur.second++;
            pq.push(cur);
        }
        while (!pq.empty())
        {
            pair<int, int> cur = pq.top();
            pq.pop();
            acc += cur.first / (double)cur.second;
        }
        return acc / (double)classes.size();
    }
};
// @lc code=end
