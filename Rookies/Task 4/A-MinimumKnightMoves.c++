#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node {
    int x, y , moves;
};

bool inside(int x, int y){
    return x>=0 && x<8 && y>=0 && y<8;
}

pair<int , int> convertPositions(const string &pos){
    return {pos[0]-'a',pos[1]-'1'};
}

int minKnightMoves(string start,string end){
    vector<pair<int ,int>>directions={
        {2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1} };
    
    pair<int, int> startPos = convertPositions(start);
    pair<int, int> endPos = convertPositions(end);

    int sx = startPos.first, sy = startPos.second;
    int ex = endPos.first, ey = endPos.second;

    if (sx == ex && sy == ey) return 0;
    
    queue<Node> q;
    q.push({sx, sy, 0});

    vector<vector<bool>> visited(8, vector<bool>(8, false));
    visited[sx][sy] = true;

    while (!q.empty()) {
        Node current = q.front();
        q.pop();

        for (const auto &direction : directions) {
            int dx = direction.first;
            int dy = direction.second;
            int nx = current.x + dx;
            int ny = current.y + dy;

            if (inside(nx, ny) && !visited[nx][ny]) {
                if (nx == ex && ny == ey) return current.moves + 1;
                visited[nx][ny] = true;
                q.push({nx, ny, current.moves + 1});
            }
        }
    }
    return -1;
}
int main()
{
    ios:: sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    
    while(t--){
    string s1 , s2;
    cin>>s1>>s2;
    
    cout<<minKnightMoves(s1,s2)<<endl;
    }    
    return 0;
}