#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &arr)
{
    int nonZeroIndex = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[nonZeroIndex]);
            nonZeroIndex++;
        }
    }
}

int main()
{
    vector<int> arr = {0, 1, 0, 3, 12};
    moveZeroes(arr);
    cout << "Array after moving zeros to the end: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}