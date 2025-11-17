#include <bits/stdc++.h>
using namespace std;

bool isPossible(int mid, vector<int> &nums, int threshold)
{
    long long res = 0;
    for (int num : nums)
    {
        res += ceil((double)num / (double)mid);
    }
    return res <= threshold;
}

int smallestDivisor(vector<int> &nums, int threshold)
{
    if (nums.size() > threshold)
        return -1;
    int low = 1; // smallest positive integer
    int high = *max_element(nums.begin(), nums.end());
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isPossible(mid, nums, threshold))
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int main()
{
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;
    cout << "Smallest divisor given threshold " << threshold << " is: " << smallestDivisor(nums, threshold) << endl;
    return 0;
}