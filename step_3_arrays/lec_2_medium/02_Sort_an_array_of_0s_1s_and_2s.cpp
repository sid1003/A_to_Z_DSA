#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int> &nums)
{

    // 2. The Initialization (Why they start there)
    // int low = 0; int mid = 0; int high = n - 1;

    // This initialization is the key. It sets up the boundaries so that, at
    // the very beginning, the "known" zones are empty and the "unknown"
    // zone is the entire array.

    // "0s" Zone: [0 ... low - 1] becomes [0 ... -1]. This is an empty,
    // non-existent range. Correct.

    // "1s" Zone: [low ... mid - 1] becomes [0 ... -1]. This is also an
    // empty range. Correct.

    // "2s" Zone: [high + 1 ... n - 1] becomes [n ... n-1]. This is also an
    // empty range. Correct.

    // "Unknown" Zone: [mid ... high] becomes [0 ... n-1]. This is the
    // entire array. Correct.

    int n = nums.size(), low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortColors(nums);
    for (auto num : nums)
    {
        cout << num << " ";
    }
    return 0;
}