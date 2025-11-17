#include <bits/stdc++.h>
using namespace std;

int linearSearch(const vector<int> &arr, int target)
{
    for (size_t i = 0; i < arr.size(); ++i)
    {
        if (arr[i] == target)
        {
            return static_cast<int>(i); // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

int main()
{
    vector<int> data = {4, 2, 5, 1, 3};
    int target = 1;

    int result = linearSearch(data, target);
    if (result != -1)
    {
        cout << "Element found at index: " << result << endl;
    }
    else
    {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}