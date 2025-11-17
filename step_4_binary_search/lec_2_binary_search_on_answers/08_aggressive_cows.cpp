#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &stalls, int minDist, int k)
{
    int cowCnt = 1;
    int lastCow = stalls[0];
    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - lastCow >= minDist)
        {
            cowCnt++;
            lastCow = stalls[i];
        }
        if (cowCnt >= k)
            return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    // code here
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int left = 1, right = stalls[n - 1] - stalls[0];
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (isPossible(stalls, mid, k))
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return right;
}

int main(){
    vector<int> stalls = {1, 2, 8, 4, 9};
    int k = 3;
    cout << "The largest minimum distance is: " << aggressiveCows(stalls, k) << endl;
    return 0;
}