#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
        {
            return 0;
        }

        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, 0));

        int result = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] != 0)
                {
                    result = max(result, dfs(matrix, memo, i, j));
                }
            }
        }

        return result;
    }

private:
    int dfs(const vector<vector<int>> &matrix, vector<vector<int>> &memo, int i, int j)
    {
        if (memo[i][j] != 0)
        {
            return memo[i][j];
        }

        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int maxPath = 1;

        for (const auto &direction : directions)
        {
            int ni = i + direction[0];
            int nj = j + direction[1];

            if (ni >= 0 && ni < matrix.size() && nj >= 0 && nj < matrix[0].size() && matrix[ni][nj] > matrix[i][j])
            {
                int length = 1 + dfs(matrix, memo, ni, nj);
                maxPath = max(maxPath, length);
            }
        }

        memo[i][j] = maxPath;
        return maxPath;
    }
};

int main()
{
    Solution solution;

    // Example usage:
    vector<vector<int>> matrix = {
        {7, 0, 4},
        {6, 0, 8},
        {2, 1, 1}};

    cout << solution.longestIncreasingPath(matrix) << endl; // Output: 4

    return 0;
}
