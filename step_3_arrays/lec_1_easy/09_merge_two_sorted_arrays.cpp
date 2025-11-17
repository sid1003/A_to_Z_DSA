#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &arr2, int n)
{
    vector<int> arr1(nums1.begin(), nums1.begin() + m);
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (arr1[i] <= arr2[j])
        {
            nums1[k] = arr1[i];
            i++;
        }
        else
        {
            nums1[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < m)
    {
        nums1[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n)
    {
        nums1[k] = arr2[j];
        j++;
        k++;
    }
}

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k] = nums1[i];
            i--;
        }
        else
        {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }
    while (j >= 0)
    {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

int main()
{
    vector<int> nums1 = {1, 3, 5, 0, 0, 0};
    int m = 3;
    vector<int> arr2 = {2, 4, 6};
    int n = 3;

    merge(nums1, m, arr2, n);

    cout << "Merged array: ";
    for (const int &num : nums1)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
