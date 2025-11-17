#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int res = 0, cnt = 0, n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
        {
            cnt = 1;
            int j = i;
            while ((j < n - 1) && (nums[j + 1] == 1))
            {
                cnt++;
                j++;
            }
            res = max(cnt, res);
            i = j;
        }
    }
    return res;
}

// this is the optimized version of the code
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int res = 0, cnt = 0, n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
            cnt++;
        else
        {
            res = max(res, cnt);
            cnt = 0;
        }
    }
    res = max(res, cnt);
    return res;
}

int main()
{
    vector<int> data = {1, 1, 0, 1, 1, 1};

    int result = findMaxConsecutiveOnes(data);
    cout << "The maximum number of consecutive 1s is: " << result << endl;

    return 0;
}