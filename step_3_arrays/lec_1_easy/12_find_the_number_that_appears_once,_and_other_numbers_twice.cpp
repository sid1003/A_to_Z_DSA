#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int res = 0;
    for (auto it : nums)
    {
        res ^= it;
    }
    return res;
}

int main()
{
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << singleNumber(nums) << endl; // Output: 4
    return 0;
}