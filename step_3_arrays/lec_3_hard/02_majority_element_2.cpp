#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
    int currMajority1 = INT_MIN, currMajority2 = INT_MIN;
    int cnt1 = 0, cnt2 = 0;
    for (int num : nums)
    {
        if (cnt1 == 0 && num != currMajority2)
        {
            cnt1 = 1;
            currMajority1 = num;
        }
        else if (cnt2 == 0 && num != currMajority1)
        {
            cnt2 = 1;
            currMajority2 = num;
        }
        else if (num == currMajority1)
            cnt1++;
        else if (num == currMajority2)
            cnt2++;
        else
        {
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0, cnt2 = 0;
    for (int num : nums)
    {
        if (num == currMajority1)
            cnt1++;
        else if (num == currMajority2)
            cnt2++;
    }
    vector<int> res;
    int n = nums.size();
    if (cnt1 > floor(n / 3))
        res.push_back(currMajority1);
    if (cnt2 > floor(n / 3))
        res.push_back(currMajority2);
    return res;
}

int main()
{
    vector<int> nums = {3, 2, 3};
    vector<int> result = majorityElement(nums);
    cout << "Majority Elements: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}