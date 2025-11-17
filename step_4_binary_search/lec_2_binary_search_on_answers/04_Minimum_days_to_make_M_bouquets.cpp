#include <bits/stdc++.h>
using namespace std;

bool isPossible(int mid, vector<int> &bloomDay, int m, int k)
{
    int cnt = 0, res = 0;
    for (int elem : bloomDay)
    {
        if (elem <= mid)
            cnt++;
        else
        {
            res += cnt / k;
            cnt = 0;
        }
    }
    res += cnt / k;
    return res >= m;
}

int minDays(vector<int> &bloomDay, int m, int k)
{
    // check if the answer exists
    int n = bloomDay.size();
    if ((double)m * (double)k > (double)n)
        return -1;
    // initializing vals for binary search
    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isPossible(mid, bloomDay, m, k))
            high = mid - 1;
        else
            low = mid + 1;
    }
    // low would contain our answer
    return low;
}

int main()
{
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3, k = 1;
    cout << "Minimum days to make " << m << " bouquets is: " << minDays(bloomDay, m, k) << endl;
    return 0;
}