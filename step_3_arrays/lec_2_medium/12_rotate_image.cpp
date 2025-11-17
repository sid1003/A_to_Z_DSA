#include <bits/stdc++.h>
using namespace std;


void transposeMatrix(vector<vector<int>> &matrix, int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        for (int j = i + 1; j <= n - 1; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}
void reverseRows(vector<vector<int>> &matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    transposeMatrix(matrix, n);
    reverseRows(matrix, n);
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    rotate(matrix);
    cout << "Rotated Matrix: " << endl;
    for (const auto &row : matrix)
    {
        for (const auto &val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}