#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int> &arr)
{
    int n = arr.size();
    vector<int> res(n, 0);
    int positiveIndex = 0, negativeIndex = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            res[negativeIndex] = arr[i];
            negativeIndex += 2;
        }
        else
        {
            res[positiveIndex] = arr[i];
            positiveIndex += 2;
        }
    }
    return res;
}

int main()
{
    vector<int> arr = {3, 1, -2, -5, 2, -4};
    vector<int> result = rearrangeArray(arr);
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}