#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &arr)
{
    // Your code here
    int n = arr.size();
    set<int> set(arr.begin(), arr.end());
    int res = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (set.find(arr[i] - 1) == set.end())
        {
            int currentElement = arr[i];
            int len = 1;
            while (set.find(currentElement + 1) != set.end())
            {
                len++;
                currentElement++;
            }
            res = max(res, len);
        }
    }
    return res;
}

int main()
{
    vector<int> arr = {100, 4, 200, 1, 3, 2};
    int result = longestConsecutive(arr);
    cout << "Length of the longest consecutive sequence is: " << result << endl;
    return 0;
}