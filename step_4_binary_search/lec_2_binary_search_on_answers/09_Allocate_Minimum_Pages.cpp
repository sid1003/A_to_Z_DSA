#include <bits/stdc++.h>
using namespace std;

bool isAllocationPossible(vector<int> &arr, int max, int k)
{
    int students_needed = 1;
    int current_student_sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (current_student_sum + arr[i] <= max)
        {
            current_student_sum += arr[i];
        }
        else
        {
            students_needed++;
            current_student_sum = arr[i];
            if (students_needed > k)
            {
                return false;
            }
        }
    }
    return students_needed <= k;
}

int findPages(vector<int> &arr, int k)
{
    // code here
    if (arr.size() < k)
        return -1;
    int left = *max_element(arr.begin(), arr.end());
    int right = accumulate(arr.begin(), arr.end(), 0);
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (isAllocationPossible(arr, mid, k))
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}

int main()
{
    vector<int> arr = {12, 34, 67, 90};
    int k = 2;
    cout << "Minimum number of pages allocated to a student is: " << findPages(arr, k) << endl;
    return 0;
}