#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int currSum = 0;
    int res = INT_MIN;
    int n = nums.size();
    int start = 0, end = 0, potential_start_index = 0;

    for (int i = 0; i < n; i++)
    {
        currSum += nums[i];

        if (currSum > res)
        {
            res = currSum;
            start = potential_start_index;
            end = i;
        }

        if (currSum < 0)
        {
            currSum = 0;
            potential_start_index = i + 1;
        }
    }

    cout << "Maximum Subarray Sum: " << res << endl;
    cout << "Subarray with Maximum Sum: ";
    for (int i = start; i <= end; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return res;
}

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(nums) << endl;
    return 0;
}