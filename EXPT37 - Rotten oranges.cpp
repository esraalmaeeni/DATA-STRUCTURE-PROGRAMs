#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int minutes = 0;
        int freshOranges = 0;
        queue<pair<int, int>> rottenOranges;

        // Count fresh oranges and initialize the queue with rotten oranges
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    freshOranges++;
                } else if (grid[i][j] == 2) {
                    rottenOranges.push({i, j});
                }
            }
        }

        // Define 4 possible directions (up, down, left, right)
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!rottenOranges.empty() && freshOranges > 0) {
            int currentSize = rottenOranges.size();

            for (int i = 0; i < currentSize; i++) {
                int x = rottenOranges.front().first;
                int y = rottenOranges.front().second;
                rottenOranges.pop();

                for (const auto& direction : directions) {
                    int newX = x + direction.first;
                    int newY = y + direction.second;

                    if (newX >= 0 && newX < rows && newY >= 0 && newY < cols &&
                        grid[newX][newY] == 1) {
                        grid[newX][newY] = 2;  // Mark the fresh orange as rotten
                        rottenOranges.push({newX, newY});
                        freshOranges--;
                    }
                }
            }

            minutes++;
        }

        return (freshOranges == 0) ? minutes : -1;
    }
};

int main() {
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    Solution solution;

    int result = solution.orangesRotting(grid);
    cout << "Minutes to rot all oranges: " << result << endl;

    return 0;
}
