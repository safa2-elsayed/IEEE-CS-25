#include <bits/stdc++.h>
#define ll long long
const int N=1e3+5;
int n ,m ,result,depth[N][N] ;

using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}
int countTrees(int n, vector<int>& p) {
   
    vector<vector<int>> graph(n + 1);
    for (int i = 1; i <= n; ++i) {
        int u = i;
        int v = p[i - 1]; 
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

   
    vector<bool> visited(n + 1, false);
    int treeCount = 0;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i, graph, visited);
            treeCount++;
        }
    }

    return treeCount;
}


int main()
{
    ios:: sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

     result = countTrees(n, p);
    cout << result << endl;


    
 return 0;
}