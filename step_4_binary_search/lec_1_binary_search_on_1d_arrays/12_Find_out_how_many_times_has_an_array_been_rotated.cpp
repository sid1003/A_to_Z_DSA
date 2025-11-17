#include <bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &arr)
{
    // Code Here
    int n = arr.size(), left = 0, right = n - 1;
    if (arr[0] <= arr[n - 1])
        return 0;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (mid != 0 && arr[mid - 1] > arr[mid])
        {
            return mid;
        }
        if (mid != n - 1 && arr[mid] > arr[mid + 1])
        {
            return mid + 1;
        }
        if (arr[mid] >= arr[left])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {15, 18, 2, 3, 6, 12};
    cout << "The array has been rotated " << findKRotation(arr) << " times." << endl;
    return 0;
}