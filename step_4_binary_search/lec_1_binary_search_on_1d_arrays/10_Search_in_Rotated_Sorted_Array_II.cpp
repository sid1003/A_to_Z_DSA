#include <bits/stdc++.h>    
using namespace std;

bool search(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
            return true;
        if (nums[low] == nums[mid] && nums[mid] == nums[high])
        {
            low++;
            high--;
            continue;
        }
        // first sorted half
        else if (nums[low] <= nums[mid])
        {
            // check if target lies in the first sorted half of the array
            if (nums[low] <= target && target <= nums[mid])
            {
                // if it does then eleminate the right half
                high = mid - 1;
            }
            else
            {
                // it it doesn't eleminate the left half
                low = mid + 1;
            }
        }
        // second sorted half
        else
        {
            // check if target lies in the second sorted half of the array
            if (nums[mid] <= target && target <= nums[high])
            {
                // if it does then eleminate the left half
                low = mid + 1;
            }
            else
            {
                // it it doesn't eleminate the left half
                high = mid - 1;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;
    if (search(nums, target))
    {
        cout << "Target found in the array" << endl;
    }
    else
    {
        cout << "Target not found in the array" << endl;
    }
    return 0;
}