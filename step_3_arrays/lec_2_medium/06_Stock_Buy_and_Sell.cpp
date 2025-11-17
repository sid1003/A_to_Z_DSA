#include <bits/stdc++.h>    
using namespace std;

int maxProfit(vector<int> &arr)
{
    int n = arr.size();
    int res = 0;
    int currProfit = 0;
    int minSoFar = arr[0];
    for (int i = 1; i < n; i++)
    {
        minSoFar = min(minSoFar, arr[i]);
        currProfit = arr[i] - minSoFar;
        res = max(currProfit, res);
    }
    return res;
}

int main()
{
    vector<int> arr = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(arr) << endl;
    return 0;
}