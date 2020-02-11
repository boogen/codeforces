#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>
 
#define ulong unsigned long long
#define ll long long
 
using namespace std;

vector<int> g[3001];

int p[3001][3001];
int dist[3001][3001];
int sub[3001][3001];
ll dp[3001][3001];

int dfs(int root, int node, int d) {
    int children = 0;
    dist[root][node] = d;
    for (int i = 0; i < g[node].size(); ++i) {
        int v = g[node][i];
        if (v != p[root][node]) {
            p[root][v] = node;
            children += dfs(root, v, d + 1);
        }
    }

    sub[root][node] = children + 1;
    return sub[root][node];
}



int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }


    for (int i = 1; i <= n; ++i) {
        p[i][i] = i;
        dfs(i, i, 0);
    }


    vector<pair<int, pair<int, int> > > paths;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            paths.push_back(make_pair(dist[i][j], make_pair(i, j)));
        }
    }

    sort(paths.begin(), paths.end());

    ll maximum = 0;
    for (int i = 0; i < paths.size(); ++i) {
        int u = paths[i].second.first;
        int v = paths[i].second.second;

        dp[u][v] = sub[u][v] * sub[v][u] + max(dp[u][p[u][v]], dp[v][p[v][u]]); 
        dp[v][u] = dp[u][v];
        if (dp[u][v] > maximum) 
            maximum = dp[u][v];
    }

    cout << maximum << endl;
}
