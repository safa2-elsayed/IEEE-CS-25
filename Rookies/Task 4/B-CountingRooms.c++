#include <bits/stdc++.h>
#define ll long long
using namespace std;


const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

bool isValid(int x, int y, int n, int m, const vector<vector<char>>& grid, vector<vector<bool>>& visited) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.' && !visited[x][y];
}

void bfs(int startX, int startY, int n, int m, const vector<vector<char>>& grid, vector<vector<bool>>& visited) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
     
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (isValid(newX, newY, n, m, grid, visited)) {
                visited[newX][newY] = true;
                q.push({newX, newY});
            }
        }
    }
}

int main() {
    ios:: sync_with_stdio(false);
    cin.tie(nullptr);
    
      int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int roomCount = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                bfs(i, j, n, m, grid, visited);
                roomCount++;
            }
        }
    }

    cout << roomCount << endl;
    return 0;
}
