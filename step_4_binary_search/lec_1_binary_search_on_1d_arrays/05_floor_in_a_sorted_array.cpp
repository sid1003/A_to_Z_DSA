#include <bits/stdc++.h>
using namespace std;

int findFloor(vector<int> &arr, int x)
{
    // code here
    int n = arr.size(), left = 0, right = n - 1, res = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= x)
        {
            res = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return res;
}

int main()
{
    vector<int> arr = {1, 2, 8, 10, 10, 12, 19};
    int x = 5;
    int index = findFloor(arr, x);
    if (index != -1)
        cout << "The floor of " << x << " is at index: " << index << endl;
    else
        cout << "No floor found for " << x << " in the array." << endl;
    return 0;
}