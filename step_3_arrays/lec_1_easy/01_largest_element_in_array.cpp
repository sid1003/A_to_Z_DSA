#include <bits/stdc++.h>
using namespace std;

int largest(vector<int> &arr)
{

    return *max_element(arr.begin(), arr.end());
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << largest(arr) << endl;
    return 0;
}