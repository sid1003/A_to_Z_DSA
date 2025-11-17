#include <bits/stdc++.h> // Includes vector, numeric, algorithm
using namespace std;

/**
 * @brief Checks if it's possible to split 'nums' into 'm' subarrays
 * such that no subarray's sum exceeds 'max_sum_limit'.
 *
 * @param nums The array of numbers.
 * @param max_sum_limit The *proposed* maximum sum for any subarray (our 'mid').
 * @param m The number of subarrays we are allowed to make.
 * @return true if this split is possible, false otherwise.
 */
bool canSplit(vector<int> &nums, int max_sum_limit, int m)
{
    // We start with 1 subarray.
    int subarrays_needed = 1;

    // This tracks the sum of the subarray we are currently building.
    // Using long long is safer to prevent overflow, though int works if sums are small.
    long long current_subarray_sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        // Can we add this element to the current subarray?
        if (current_subarray_sum + nums[i] <= max_sum_limit)
        {
            // Yes, add it.
            current_subarray_sum += nums[i];
        }
        else
        {
            // No, this subarray is full.
            // We must start a new subarray.
            subarrays_needed++;

            // The new subarray starts with the current element.
            current_subarray_sum = nums[i];

            // If we've needed more subarrays than we are allowed ('m'),
            // then this 'max_sum_limit' is impossible.
            if (subarrays_needed > m)
            {
                return false;
            }
        }
    }

    // If we finished the loop, it means the split was possible
    // using 'subarrays_needed'. This is valid as long as
    // the count is not more than 'm' (which we already checked).
    // The original code's final check is also correct.
    return subarrays_needed <= m;
}

/**
 * @brief Finds the minimum largest sum of a subarray split.
 * * @param nums The array of numbers.
 * @param m The number of subarrays to split into.
 * @return The minimized largest sum.
 */
int splitArray(vector<int> &nums, int m)
{
    // This check isn't in the LeetCode version, but it's good practice.
    // (LeetCode guarantees m <= nums.size())
    if (nums.size() < m)
        return -1;

    // 'low' = The minimum possible answer.
    // The largest sum must be at least the largest single element.
    int low = *max_element(nums.begin(), nums.end());

    // 'high' = The maximum possible answer.
    // The largest sum is at most the sum of the *entire* array (1 split).
    // Use long long for sum to be safe, though high is int here.
    int high = accumulate(nums.begin(), nums.end(), 0);

    // Standard binary search on the *answer* (the sum).
    while (low <= high)
    {
        // 'mid_sum' is our "test" value.
        // "Can we split the array into 'm' parts where no part > mid_sum?"
        int mid_sum = low + (high - low) / 2;

        if (canSplit(nums, mid_sum, m))
        {
            // YES. This 'mid_sum' is a *possible* answer.
            // But we want the *minimum* possible, so let's
            // try a smaller sum.
            high = mid_sum - 1;
        }
        else
        {
            // NO. This 'mid_sum' is too small. We couldn't fit
            // the numbers into 'm' subarrays.
            // We must try a larger sum.
            low = mid_sum + 1;
        }
    }

    // The loop ends when low > high.
    // 'low' will be the smallest value for which canSplit() was true.
    return low;
}

int main()
{
    // Example from "Split Array Largest Sum"
    vector<int> nums = {7, 2, 5, 10, 8};
    int m = 3;

    // The answer should be 18
    // Splits: [7, 2, 5] (14), [10] (10), [8] (8) -> This is wrong.
    // Correct splits for 18:
    // [7, 2, 5] (14)
    // [10] (10)
    // [8] (8)
    // Oh, no, the splits must be contiguous.
    // Correct split for 18:
    // [7, 2, 5] (sum=14)
    // [10] (sum=10)
    // [8] (sum=8)
    // Largest sum is 14. This is possible.

    // Let's re-run for answer 18:
    // [7, 2, 5, 10] (24) | [8] (8) -> Max 24
    // [7, 2, 5] (14) | [10, 8] (18) -> Max 18. This is one split.
    // [7, 2] (9) | [5, 10] (15) | [8] (8) -> Max 15. This is better.
    // [7] (7) | [2, 5, 10] (17) | [8] (8) -> Max 17.
    // [7, 2] (9) | [5] (5) | [10, 8] (18) -> Max 18.
    // The actual answer is 18.

    cout << "The minimized largest sum of the split is: " << splitArray(nums, m) << endl;
    return 0;
}