#include <bits/stdc++.h>
using namespace std;

bool isPossible(int capacity, vector<int> &weights, int days)
{
    int day = 1;
    int currSum = 0;
    for (int weight : weights)
    {
        if (weight > capacity)
            return false;
        currSum += weight;
        if (currSum > capacity)
        {
            day++;
            currSum = weight;
            if (day > days)
                return false;
        }
    }
    return true;
}

int shipWithinDays(vector<int> &weights, int days)
{
    if (days <= 0)
        return -1;
    long long low = *max_element(weights.begin(), weights.end());
    // we want to be able to ship all items if the capaicty of the ship is
    // less than the max element then we won't be able to carry the max element
    long long high = accumulate(weights.begin(), weights.end(), 0);
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isPossible(mid, weights, days))
            high = mid - 1;
        else
            low = mid + 1;
    }
    return (int)low;
}

int main()
{
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;
    cout << "Minimum capacity to ship packages within " << days << " days is: " << shipWithinDays(weights, days) << endl;
    return 0;
}