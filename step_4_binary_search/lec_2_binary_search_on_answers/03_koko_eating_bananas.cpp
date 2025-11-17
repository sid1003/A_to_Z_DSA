#include <bits/stdc++.h>
using namespace std;

long long totalHours(vector<int> &piles, int hours)
{
    long long res = 0;
    for (int pile : piles)
    {
        res += ceil((double)(pile) / (double)(hours));
    }
    return res;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (totalHours(piles, mid) <= h)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    cout << "Minimum eating speed to finish all bananas in " << h << " hours is: " << minEatingSpeed(piles, h) << endl;
    return 0;
}