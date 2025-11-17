#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int target)
{
    // code here
    int n = arr.size(), left = 0, right = n - 1, res = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] > target)
        {
            res = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    if (res == -1)
        return n;
    return res;
}

int main()
{
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    int target = 2;
    int index = upperBound(arr, target);
    cout << "The upper bound index of " << target << " is: " << index << endl;
    return 0;
}