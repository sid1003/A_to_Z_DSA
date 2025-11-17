#include <bits/stdc++.h>
using namespace std;

int findCeil(vector<int> &arr, int x)
{
    int n = arr.size();
    if (arr[n - 1] < x)
        return -1;
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int main()
{
    vector<int> arr = {1, 2, 8, 10, 10, 12, 19};
    int x = 9;
    int index = findCeil(arr, x);
    if (index != -1)
        cout << "The ceil of " << x << " is at index: " << index << endl;
    else
        cout << "No ceil found for " << x << " in the array." << endl;
    return 0;
}