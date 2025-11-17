#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int> &nums, int n, int left, int right)
{
    if (left >= 0 && left < n && right >= 0 && right < n)
    {
        while (left <= right)
        {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
}

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    if (k % n == 0)
        return;
    k %= n;
    reverse(nums, n, 0, n - k - 1);
    reverse(nums, n, n - k, n - 1);
    reverse(nums, n, 0, n - 1);
}

int main()
{
    vector<int> nums = {1, 2, 3, 4,
                        5, 6, 7};
    int k = 3;
    rotate(nums, k);
    cout << "Array after rotating by " << k << " places: ";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}