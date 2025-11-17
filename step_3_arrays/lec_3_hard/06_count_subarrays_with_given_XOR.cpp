#include <bits/stdc++.h>
using namespace std;

long subarrayXor(vector<int> &arr, int k)
{
    int n = arr.size();
    long ans = 0;
    int preXor = 0;
    unordered_map<int, int> map;
    map[preXor]++; // adding 0 => 1
    for (int i = 0; i < n; i++)
    {
        preXor ^= arr[i];
        int complimentXor = preXor ^ k;
        ans += map[complimentXor];
        map[preXor]++;
    }
    return ans;
}

int main()
{
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;
    cout << "Count of subarrays with given XOR is " << subarrayXor(arr, k) << endl;
    return 0;
}