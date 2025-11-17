#include <bits/stdc++.h>
using namespace std;

vector<int> leaders(vector<int> &arr)
{
    // Code here
    int n = arr.size(), maxSoFar = arr[n - 1];
    vector<int> res;
    res.push_back(arr[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] >= maxSoFar)
        {
            maxSoFar = arr[i];
            res.push_back(maxSoFar);
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    vector<int> result = leaders(arr);
    for (int leader : result)
    {
        cout << leader << " ";
    }
    return 0;
}