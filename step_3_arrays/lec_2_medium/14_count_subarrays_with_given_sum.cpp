#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &arr, int k)
{
    int n = arr.size();
    unordered_map<int, int> mp;
    mp[0] = 1;
    int cnt = 0;
    int preSum = 0;
    for (int i = 0; i < n; i++)
    {
        preSum += arr[i];
        int remaining = preSum - k;
        if (mp.find(remaining) != mp.end())
        {
            cnt += mp[remaining];
        }
        mp[preSum]++;
    }
    return cnt;
}

int main()
{
    vector<int> arr = {1, 1, 1};
    int k = 2;
    int result = subarraySum(arr, k);
    cout << "Number of subarrays with sum " << k << " is: " << result << endl;
    return 0;
}