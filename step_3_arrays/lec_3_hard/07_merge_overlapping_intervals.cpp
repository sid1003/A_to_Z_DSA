#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &arr)
{
    int n = arr.size();
    vector<vector<int>> res;
    if (n == 0)
        return res;

    sort(arr.begin(), arr.end());

    vector<int> currInterval = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i][0] <= currInterval[1])
        {
            currInterval[1] = max(currInterval[1], arr[i][1]);
        }
        else
        {
            res.push_back(currInterval);
            currInterval = arr[i];
        }
    }

    res.push_back(currInterval);
    return res;
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {2, 4}, {5, 7}, {6, 8}};
    vector<vector<int>> mergedIntervals = merge(arr);
    cout << "Merged Intervals are: " << endl;
    for (const auto &interval : mergedIntervals)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
    return 0;
}