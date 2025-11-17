#include <bits/stdc++.h>
using namespace std;

int maxLen(vector<int> &arr)
{
    int n = arr.size();
    int res = 0;
    int sum = 0;
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
            res = i + 1;
        else
        {
            if (map.find(sum) != map.end())
            {
                res = max(res, i - map[sum]);
            }
            else
            {
                map[sum] = i;
            }
        }
    }
    return res;
}

int main()
{
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};
    cout << "Length of the longest 0 sum subarray is " << maxLen(arr) << endl;
    return 0;
}