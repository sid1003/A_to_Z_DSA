#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &nums)
{
    int n = nums.size();
    int pre = 1, suf = 1;
    int res = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (pre == 0)
            pre = 1;
        if (suf == 0)
            suf = 1;
        pre *= nums[i];
        suf *= nums[n - i - 1];
        res = max(res, max(pre, suf));
    }
    return res;
}

int main()
{
    vector<int> nums = {2, 3, -2, 4};
    int ans = maxProduct(nums);
    cout << "The maximum product subarray is: " << ans << endl;
    return 0;
}