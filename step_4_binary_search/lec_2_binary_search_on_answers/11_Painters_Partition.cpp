#include <bits/stdc++.h> // Includes vector, numeric, algorithm
using namespace std;

/**
 * @brief Checks if it's possible to paint all boards with 'k' painters
 * such that no painter works for more than 'max_time_limit'.
 *
 * @param boards The array of board lengths.
 * @param max_time_limit The *proposed* max time (our 'mid' value).
 * @param k The number of painters available.
 * @return true if this time limit is possible, false otherwise.
 */
bool canPaint(vector<int> &boards, int max_time_limit, int k)
{
    // We start needing 1 painter
    int painters_needed = 1;

    // Tracks the total length (time) for the current painter
    long long current_painter_sum = 0; // Use long long for safety

    for (int i = 0; i < boards.size(); i++)
    {
        // Can the current painter take this board?
        if (current_painter_sum + boards[i] <= max_time_limit)
        {
            // Yes, add this board's length to their total
            current_painter_sum += boards[i];
        }
        else
        {
            // No, this painter is full. We need a new painter.
            painters_needed++;

            // The new painter starts with this current board
            current_painter_sum = boards[i];

            // If we've needed more painters than we have ('k'),
            // then this 'max_time_limit' is impossible.
            if (painters_needed > k)
            {
                return false;
            }
        }
    }

    // If we finished the loop, the partition is possible
    // as long as we didn't use more than 'k' painters.
    return painters_needed <= k;
}

/**
 * @brief Finds the minimum time required to paint all boards.
 * @param boards The array of board lengths.
 * @param k The number of painters.
 * @return The minimized maximum time.
 */
int paintersPartition(vector<int> &boards, int k)
{
    // If we have more painters than boards, it's not a
    // valid scenario per the problem (or can be optimized,
    // but often this check is for problem constraints).
    if (boards.size() < k)
        return -1;

    // 'low' = The minimum possible answer.
    // The time must be *at least* the length of the longest board
    // (since one painter must paint it).
    int low = *max_element(boards.begin(), boards.end());

    // 'high' = The maximum possible answer.
    // The worst case is 1 painter paints all boards.
    int high = accumulate(boards.begin(), boards.end(), 0);

    // Binary search on the *answer* (the time).
    while (low <= high)
    {
        // 'mid_time' is our "test" value.
        // "Can we paint all boards with a max time of 'mid_time'?"
        int mid_time = low + (high - low) / 2;

        if (canPaint(boards, mid_time, k))
        {
            // YES. This 'mid_time' is a *possible* answer.
            // But we want the *minimum* possible time, so
            // let's try an even smaller time.
            high = mid_time - 1;
        }
        else
        {
            // NO. This 'mid_time' is too small. We couldn't
            // paint all boards with 'k' painters.
            // We must try a larger time.
            low = mid_time + 1;
        }
    }

    // The loop ends when low > high.
    // 'low' will be the smallest time for which canPaint() was true.
    return low;
}

int main()
{
    vector<int> boards = {10, 20, 30, 40};
    int k = 2; // 2 painters

    // The answer should be 60.
    // Painter 1 takes [10, 20, 30] (sum=60)
    // Painter 2 takes [40] (sum=40)
    // The max time is 60, which is the minimum possible max.

    cout << "The minimum time to paint all boards is: "
         << paintersPartition(boards, k) << endl;

    return 0;
}