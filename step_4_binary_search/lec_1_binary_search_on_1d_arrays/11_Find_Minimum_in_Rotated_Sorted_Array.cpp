#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &nums)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        // check if the first half is sorted
        if (nums[low] <= nums[mid])
        {
            ans = min(nums[low], ans);
            low = mid + 1;
        }
        else
        {
            ans = min(nums[mid], ans);
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {3, 4, 5, 1, 2};
    cout << "The minimum element in the rotated sorted array is: " << findMin(nums) << endl;
    return 0;
}