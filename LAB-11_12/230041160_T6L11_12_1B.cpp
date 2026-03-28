#include <iostream>
#include <vector>
using namespace std;

int m, n;

void dfs(int r, int c, vector<vector<int>> &grid, vector<vector<bool>> &visited, int prevHeight)
{
    if (r < 0 || r >= m || c < 0 || c >= n)
        return;

    if (visited[r][c])
        return;

    if (grid[r][c] < prevHeight)
        return;

    visited[r][c] = true;

    dfs(r + 1, c, grid, visited, grid[r][c]);
    dfs(r - 1, c, grid, visited, grid[r][c]);
    dfs(r, c + 1, grid, visited, grid[r][c]);
    dfs(r, c - 1, grid, visited, grid[r][c]);
}
int main()
{

    if (!(cin >> m >> n))
        return 0;

    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> reachedGreen(m, vector<bool>(n, false));
    vector<vector<bool>> reachedRed(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++){
        dfs(i, 0, grid, reachedGreen, grid[i][0]);
    }

    for (int j = 0; j < n; j++){
        dfs(0, j, grid, reachedGreen, grid[0][j]);
    }

    for (int i = 0; i < m; i++){
        dfs(i, n - 1, grid, reachedRed, grid[i][n - 1]);
    }

    for (int j = 0; j < n; j++){
        dfs(m - 1, j, grid, reachedRed, grid[m - 1][j]);
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (reachedGreen[i][j] && reachedRed[i][j]){
                cout << "O ";
            }
            else{
                cout << "X ";
            }
        }
        cout << "\n";
    }
    return 0;
}