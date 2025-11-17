#include <bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int> &arr, int k)
{
    // Get the size of the array
    int n = arr.size();

    // Initialize the binary search boundaries
    // 'low' will point to the start index, 'high' to the end index
    int low = 0, high = n - 1;

    // Standard binary search loop.
    // We are not searching for a specific *value*, but for the
    // "pivot point" in the array which helps us find k.
    while (low <= high)

    {
        // Calculate the middle index, avoiding potential overflow (low + high) / 2
        int mid = low + (high - low) / 2;

        /*
         * ### 1. The Core Idea ###
         * This line calculates how many positive numbers are missing
         * *up to* the index `mid`.
         *
         * How it works:
         * 1. In a "perfect" array with no missing numbers (e.g., [1, 2, 3, 4, ...]),
         * the value at any index `i` would be exactly `i + 1`.
         * (e.g., arr[0] = 1, arr[1] = 2, ...)
         *
         * 2. Our given array `arr` has missing numbers, so `arr[mid]` will be
         * larger than or equal to what it would be in a perfect array (`mid + 1`).
         *
         * 3. The difference, `arr[mid] - (mid + 1)`, gives us the exact count
         * of numbers that have been "skipped" or "missed" to get to arr[mid].
         *
         * Example: arr = [2, 3, 4, 7, 11]
         * If mid = 2:
         * - arr[mid] = 4
         * - "perfect" value = mid + 1 = 3
         * - missing = 4 - 3 = 1. (This is correct, only the number '1' is missing)
         *
         * If mid = 3:
         * - arr[mid] = 7
         * - "perfect" value = mid + 1 = 4
         * - missing = 7 - 4 = 3. (Correct again: '1', '5', '6' are missing)
         */
        int missing = arr[mid] - (mid + 1);

        /*
         * ### 2. The Binary Search Logic ###
         * We use the `missing` count to decide where to search next.
         */

        // If the number of missing elements at `mid` is LESS than k...
        if (missing < k)

        {
            // ...it means the k-th missing number must be *after* arr[mid].
            // We haven't found enough missing numbers yet, so we need to
            // search in the right half of the array.
            low = mid + 1;
        }
        // If the number of missing elements at `mid` is GREATER THAN OR EQUAL to k...
        else
        {
            // ...it means the k-th missing number is either *before* arr[mid]
            // or one of the numbers leading up to it.
            // We must search in the left half to find this "crossover" point.
            high = mid - 1;
        }

    } // End of while loop

    /*
     * ### 3. The Final Result: `return low + k;` ###
     *
     * When the loop terminates, `low` and `high` have crossed.
     * - `high` is the index of the last element where missing < k.
     * - `low` is the index of the first element where missing >= k.
     *
     * This means `low` now represents the **total count of elements from `arr`
     * that are SMALLER than the k-th missing number.**
     *
     * Let's think about the final answer. The k-th missing number's value
     * is part of the complete sequence of positive integers [1, 2, 3, ...].
     * This sequence is made of two groups:
     * 1. Numbers *present* in `arr` (up to a certain point).
     * 2. Numbers *missing* from `arr`.
     *
     * The k-th missing number's value is simply the sum of:
     * (Count of *present* numbers before it) + (Count of *missing* numbers up to it)
     *
     * - The (Count of *missing* numbers) is exactly `k`.
     * - The (Count of *present* numbers) is what our binary search found: `low`.
     *
     * Example: arr = [2, 3, 4, 7, 11], k = 5
     * Loop ends with `low = 4`.
     * This means 4 elements from `arr` ([2, 3, 4, 7]) are smaller than our target.
     *
     * Answer = low + k = 4 + 5 = 9.
     *
     * Let's check:
     * Numbers up to 9: [1, 2, 3, 4, 5, 6, 7, 8, 9]
     * Present in arr:  [   2, 3, 4,    7      ] (Count = 4 = low)
     * Missing from arr: [1,       5, 6,    8, 9] (Count = 5 = k)
     * The 5th (k-th) missing number is indeed 9.
     */
    return low + k;
}

int main()
{
    // Example test case
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;

    // Call the function and print the result
    cout << "The " << k << "th missing positive number is: " << findKthPositive(arr, k) << endl;
    // Expected output: 9
    return 0;
}