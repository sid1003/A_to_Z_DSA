#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums)
{
    int count = 0;
    int candidate = 0;

    for (int num : nums)
    {
        if (count == 0)
            candidate = num;
            
        if (num == candidate)
            count++;
        else
            count--;
    }

    return candidate;
    // count = 0;
    // for(int i = 0 ; i < n ; i++){
    //     if(nums[i] == res) count++;
    // }
    // if(count > n / 2) return candidate;
    // else return -1;
}

int main()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << majorityElement(nums) << endl;
    return 0;
}