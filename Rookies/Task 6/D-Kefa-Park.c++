#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; 
vector<int> values; 
vector<bool> vis;   
int result = 0;          
int max_cost;            

void dfs(int node, int currentcost) {
    vis[node] = true;

    if (currentcost > max_cost) {
        return;
    }

    if (adj[node].size() == 1 && node != 1) { 
        result++;
        return;
    }

    for (int neighbor : adj[node]) {
        if (!vis[neighbor]) {
            dfs(neighbor, currentcost + values[neighbor]);
        }
    }
}

int main() {
    int n;
    cin >> n >> max_cost;

    adj.resize(n + 1);
    values.resize(n + 1);
    vis.resize(n + 1, false);
    for (int i = 1; i <= n; i++) {
        cin >>values[i];
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, values[1]);
    cout << result << endl;

    return 0;
}