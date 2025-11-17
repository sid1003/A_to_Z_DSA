#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &nums)
{
    int n = nums.size(), left = 1, right = n - 2;
    if (n == 1)
        return 0;
    if (n >= 2 && nums[0] > nums[1])
        return 0;
    if (n >= 2 && nums[n - 1] > nums[n - 2])
        return n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
        {
            return mid;
        }
        else if (nums[mid] > nums[mid - 1])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    cout << "The peak element is at index: " << findPeakElement(nums) << endl;
    return 0;
}