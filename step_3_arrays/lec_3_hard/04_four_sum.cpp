#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i = 0; i < n - 3; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < n - 2; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            int left = j + 1;
            int right = n - 1;
            while (left < right)
            {
                long long currSum =
                    (long long)nums[i] + nums[j] + nums[left] + nums[right];
                if (currSum == target)
                {
                    res.push_back(
                        {nums[i], nums[j], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
                else if (currSum < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> result = fourSum(nums, target);
    cout << "Four Sum results:" << endl;
    for (const auto &quadruplet : result)
    {
        for (int num : quadruplet)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}