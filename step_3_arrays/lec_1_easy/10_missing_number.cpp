#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int sum = n * (n + 1) / 2;
    int sum2 = accumulate(nums.begin(), nums.end(), 0);
    return sum - sum2;
}

int main()
{
    vector<int> data = {3, 0, 1};

    int result = missingNumber(data);
    cout << "The missing number is: " << result << endl;

    return 0;
}