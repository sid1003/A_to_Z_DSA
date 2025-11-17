#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k)
{
    int left = 0, right = 0;
    long long current_sum = 0;
    int maxLen = 0;
    int n = a.size();

    while (right < n)
    {
        // 1. Expand the window
        current_sum += a[right];

        // 2. Shrink the window if sum is too large
        while (current_sum > k && left <= right)
        {
            current_sum -= a[left];
            left++;
        }

        // 3. Check if we found a valid sum
        if (current_sum == k)
        {
            maxLen = max(maxLen, (right - left + 1));
        }

        // 4. Continue expanding
        right++;
    }
    return maxLen;
}

int main()
{
    vector<int> a = {10, 5, 2, 7, 1, 9};
    long long k = 15;
    cout << longestSubarrayWithSumK(a, k) << endl; // Output: 4
    return 0;
}