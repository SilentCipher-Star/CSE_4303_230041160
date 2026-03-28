#include <iostream>
#include <vector>
#include <string>
using namespace std;

int m, n;

void sinkIsland(int r, int c, vector<string> &grid)
{

    if (r < 0 || r >= m || c < 0 || c >= n)
        return;

    if (grid[r][c] == '0')
        return;

    grid[r][c] = '0';

    sinkIsland(r + 1, c, grid);
    sinkIsland(r - 1, c, grid);
    sinkIsland(r, c + 1, grid);
    sinkIsland(r, c - 1, grid);
}
int main()
{

    if (!(cin >> m >> n))
        return 0;

    vector<string> grid(m);

    for (int i = 0; i < m; i++)
    {
        
       cin >> grid[i];
        
    }

    int islands = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '1')
            {
                islands++;

                sinkIsland(i, j, grid);
            }
        }
    }

    cout << islands << endl;
    return 0;
}
