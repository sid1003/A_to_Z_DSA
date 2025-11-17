#include <bits/stdc++.h>
using namespace std;

vector<int> generateRow(int n)
{
    vector<int> res;
    int ans = 1;
    res.push_back(ans);
    for (int i = 1; i < n; i++)
    {
        ans *= n - i;
        ans /= i;
        res.push_back(ans);
    }
    return res;
}

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> res;
    for (int i = 1; i <= numRows; i++)
    {
        res.push_back(generateRow(i));
    }
    return res;
}

int main()
{
    int numRows = 5;
    vector<vector<int>> result = generate(numRows);
    cout << "Pascal's Triangle with " << numRows << " rows:" << endl;
    for (const auto &row : result)
    {
        for (const auto &val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}