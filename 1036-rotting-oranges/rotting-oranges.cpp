class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        int fresh = 0;
        int minutes = 0;

        // Store all rotten oranges
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 2) {
                    q.push({i, j});
                }

                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        // No fresh oranges
        if (fresh == 0)
            return 0;

        int dir[4][2] = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };

        while (!q.empty()) {

            int size = q.size();
            bool rotted = false;

            for (int i = 0; i < size; i++) {

                auto [r, c] = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {

                    int nr = r + dir[d][0];
                    int nc = c + dir[d][1];

                    if (nr >= 0 && nr < m &&
                        nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {

                        grid[nr][nc] = 2;

                        fresh--;

                        q.push({nr, nc});

                        rotted = true;
                    }
                }
            }

            if (rotted)
                minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};