#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &arr, int target)
{
    // code here
    int n = arr.size(), left = 0, right = n - 1, ans = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            ans = mid;
            right = mid - 1;
        }
        else if (arr[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    if (ans == -1)
        return left;
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    int target = 2;
    int index = lowerBound(arr, target);
    cout << "The lower bound index of " << target << " is: " << index << endl;
    return 0;
}