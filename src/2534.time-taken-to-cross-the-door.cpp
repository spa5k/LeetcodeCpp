/*
 * @lc app=leetcode id=2534 lang=cpp
 *
 * [2534] Time taken to cross the door.
 */
#include <headers.h>

// @lc code=start
class Solution
{
public:
    vector<int> timeTaken(vector<int> &arrival, vector<int> &state)
    {
        vector<int> result(arrival.size());          // To store the crossing time for each person
        queue<pair<int, int>> exitQueue, enterQueue; // Queues to store people who want to exit and enter
        int currentTime = 0;                         // Current time

        // Fill the enterQueue and exitQueue based on the arrival and state arrays
        for (int i = 0; i < arrival.size(); i++)
        {
            // If the person wants to exit, add them to the exitQueue, otherwise add them to the enterQueue
            if (state[i] == 1)
                exitQueue.push({i, arrival[i]});
            else
                enterQueue.push({i, arrival[i]});
        }

        // Loop until both enterQueue and exitQueue are empty
        while (!enterQueue.empty() || !exitQueue.empty())
        {
            // Update the current time to be the maximum of the arrival times of the front elements of enterQueue and exitQueue
            currentTime = max(currentTime, min(exitQueue.empty() ? INT_MAX : exitQueue.front().second,
                                               enterQueue.empty() ? INT_MAX : enterQueue.front().second));

            // Process people who want to exit first if they arrive at or before the current time
            while (!exitQueue.empty() && exitQueue.front().second <= currentTime)
            {
                result[exitQueue.front().first] = currentTime++;
                exitQueue.pop();
            }

            // Process people who want to enter if they arrive at or before the current time
            while (!enterQueue.empty() && enterQueue.front().second <= currentTime)
            {
                result[enterQueue.front().first] = currentTime++;
                enterQueue.pop();
            }
        }

        return result;
    }
};
// @lc code=end
