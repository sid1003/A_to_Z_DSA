#include <bits/stdc++.h>
using namespace std;

int findFirst(vector<int> &arr, int target)
{
    int n = arr.size();
    int low = 0, high = n - 1, first = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            first = mid;    // might be a potential answer;
            high = mid - 1; // go to the left to find the first
        }
        else if (arr[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return first;
}

int findLast(vector<int> &arr, int target)
{
    int n = arr.size();
    int low = 0, high = n - 1, last = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            last = mid;    // might be a potential answer;
            low = mid + 1; // go to the right to find the last
        }
        else if (arr[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return last;
}

int countFreq(vector<int> &arr, int target)
{
    int first = findFirst(arr, target);
    if (first == -1)
        return 0;
    int last = findLast(arr, target);
    return last - first + 1;
}

int main()
{
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    int target = 2;
    int count = countFreq(arr, target);
    cout << "The count of occurrences of " << target << " is: " << count << endl;
    return 0;
}