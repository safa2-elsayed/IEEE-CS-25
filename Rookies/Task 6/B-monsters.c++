#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, m;
char grid[N][N];
bool visited[N][N];
int dist[N][N];  
pair<int, int> parent[N][N];  

const int dx[] = {-1, 1, 0, 0}; 
const int dy[] = {0, 0, -1, 1};
const char dir[] = {'U', 'D', 'L', 'R'};

queue<pair<int, int>> monsterQueue, playerQueue;
pair<int, int> start;
vector<vector<int>> monsterDist;

bool IsValid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#' && !visited[x][y]);
}

void dfsMonsters() {
    while (!monsterQueue.empty()) {
        int x = monsterQueue.front().first;
        int y = monsterQueue.front().second;
        monsterQueue.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (IsValid(nx, ny) && monsterDist[nx][ny] == -1) {
                monsterDist[nx][ny] = monsterDist[x][y] + 1;
                monsterQueue.push({nx, ny});
            }
        }
    }
}


bool dfsPlayer() {
    while (!playerQueue.empty()) {
        int x = playerQueue.front().first;
        int y = playerQueue.front().second;
        playerQueue.pop();

        if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
            string path;
            while (make_pair(x, y) != start) {
                pair<int, int> p = parent[x][y];
                for (int d = 0; d < 4; d++) {
                    if (p.first + dx[d] == x && p.second + dy[d] == y) {
                        path += dir[d];
                        break;
                    }
                }
                x = p.first;
                y = p.second;
            }
            reverse(path.begin(), path.end());
            cout << "YES\n" << path.size() << "\n" << path << "\n";
            return true;
        }

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (IsValid(nx, ny) && dist[nx][ny] == -1 && (monsterDist[nx][ny] == -1 || dist[x][y] + 1 < monsterDist[nx][ny])) {
                dist[nx][ny] = dist[x][y] + 1;
                parent[nx][ny] = {x, y};
                playerQueue.push({nx, ny});
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    monsterDist.assign(n, vector<int>(m, -1));
    memset(visited, false, sizeof(visited));
    memset(dist, -1, sizeof(dist));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];

            if (grid[i][j] == 'M') {
                monsterQueue.push({i, j});
                monsterDist[i][j] = 0;
            }
            if (grid[i][j] == 'A') {
                start = {i, j};
                playerQueue.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    dfsMonsters(); 
    if (!dfsPlayer()) {
        cout << "NO\n";
    }

    return 0;
}