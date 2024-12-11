#include <bits/stdc++.h>
using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
const char dir[] = {'L','D','R','U'};

int main() {
    ios:: sync_with_stdio(false);
    cin.tie(nullptr);
  
    int n, m;
    cin >> n >> m;

    vector<string> labyrinth(n);
    for (int i = 0; i < n; ++i) {
        cin >> labyrinth[i];
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> parent_dir(n, vector<int>(m, -1));

    pair<int, int> start, end;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (labyrinth[i][j] == 'A') {
                start = {i, j};
            } else if (labyrinth[i][j] == 'B') {
                end = {i, j};
            }
        }
    }
     queue<pair<int, int>> q;
     q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty()) {
         int x = q.front().first;
         int y = q.front().second;
         q.pop();
         
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && labyrinth[nx][ny] != '#') {
                visited[nx][ny] = true;
                parent_dir[nx][ny] = i;
                q.push({nx, ny});

                if (nx == end.first && ny == end.second) {
                    string path;
                    while (nx != start.first || ny != start.second) {
                        int d = parent_dir[nx][ny];
                        path += dir[d];
                        nx -= dx[d];
                        ny -= dy[d];
                    }
                    reverse(path.begin(), path.end());
                    cout << "YES\n";
                    cout << path.size() << "\n";
                    cout << path << "\n";
                    return 0;
                }
            }
        }
    }
     cout << "NO\n";
    return 0;
}
