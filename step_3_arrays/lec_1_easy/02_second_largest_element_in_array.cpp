#include <bits/stdc++.h>
using namespace std;

int getSecondLargest(vector<int> &arr)
{
    // code here
    int largest = INT_MIN, secondLargest = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] < largest)
        {
            secondLargest = arr[i];
        }
    }

    return secondLargest == INT_MIN ? -1 : secondLargest;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << getSecondLargest(arr) << endl;
    return 0;
}