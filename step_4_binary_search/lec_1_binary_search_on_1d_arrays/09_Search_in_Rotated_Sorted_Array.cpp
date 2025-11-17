#include <vector>
using namespace std;

int search(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
            return mid;

        // first half is sorted
        else if (nums[mid] >= nums[left])
        {
            // target is in the first half
            if (target >= nums[left] && target <= nums[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        // second half is sorted
        else
        {
            // target is in the second half
            if (target >= nums[mid] && target <= nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{
    // give some test cases and print the results
    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    int target1 = 0;
    int result1 = search(nums1, target1);
    // Expected output: 4
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    int target2 = 3;
    int result2 = search(nums2, target2);

    // Expected output: -1

    return 0;
}